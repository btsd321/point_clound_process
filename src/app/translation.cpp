#include <QLocale>
#include <QApplication>
#include <QTranslator>
#include <QsLog/QsLog.h>
#include "app/translation.h"
#include "common/global.h"

namespace btsd
{
    BOOL CTranslation::m_b_initflag = FALSE;
    EM_LANGUAGE_TYPE CTranslation::m_emLanguageType = EM_LANGUAGE_TYPE_CHINESE;
    QMap<EM_LANGUAGE_TYPE, QPointer<QTranslator>> CTranslation::m_maptranslators = QMap<EM_LANGUAGE_TYPE, QPointer<QTranslator>>();

    const QString language_file_name[EM_LANGUAGE_TYPE_MAX] = {
        "point_clound_process_zh_CN.qm",
        "point_clound_process_en_AS.qm",
    };

    CTranslation* CTranslation::Instance()
    {
        static CTranslation instance;
        return &instance;
    }

    ENUM_LANGUAGE_TYPE CTranslation::GetCurLanguageType()
    {
        return CTranslation::m_emLanguageType;
    }

    void CTranslation::Init()
    {
        if(m_b_initflag)
        {
            return;
        }
        m_b_initflag = TRUE;

        //加载已有的翻译文件
        QPointer<QTranslator> ptranslator;
        for(INT32 i = 0; i < EM_LANGUAGE_TYPE_MAX; i++)
        {
            ptranslator = new QTranslator(CTranslation::Instance());
            QString file_path(TRANSLATION_FLODER_NAME);

            if (ptranslator->load(file_path + "/" + language_file_name[i]))
            {
                CTranslation::m_maptranslators.insert((EM_LANGUAGE_TYPE)i, ptranslator);
                QLOG_INFO() << "load lauguage file:" << language_file_name[i];
            }
            else
            {
                QLOG_WARN() << "Failed to load lauguage file:" << language_file_name[i];
            }
        }

        if(CTranslation::m_maptranslators.empty())
        {
            QLOG_FATAL() << "No language files are loaded.";
            return;
        }

        if(CTranslation::m_maptranslators.size() != EM_LANGUAGE_TYPE_MAX)
        {
            QLOG_WARN() << "Not all language files are loaded.";
        }

        //打印查找到的翻译文件总数
        QLOG_INFO() << "Total number of language files loaded:" << CTranslation::m_maptranslators.size();

        //遍历QMap查找是否有和系统语言相同的翻译文件
        const QStringList uiLanguages = QLocale::system().uiLanguages();
        QLOG_INFO() << "System language:" << uiLanguages;

        if((uiLanguages.contains("zh-CN"))||(uiLanguages.contains("zh")))
        {
            //查找MAP中是否有中文翻译文件
            for(auto iter = CTranslation::m_maptranslators.begin(); iter != CTranslation::m_maptranslators.end(); iter++)
            {
                if(iter.key() == EM_LANGUAGE_TYPE_CHINESE)
                {
                    CTranslation::m_emLanguageType = EM_LANGUAGE_TYPE_CHINESE;
                    if(QCoreApplication::instance()->installTranslator(iter.value().get()))
                    {
                        QLOG_INFO() << "install lauguage file:" << language_file_name[CTranslation::m_emLanguageType];
                        return;
                    }
                    else
                    {
                        QLOG_WARN() << "Failed to install lauguage file:" << language_file_name[CTranslation::m_emLanguageType];
                    }
                    return;
                }
            }
        }

        if((uiLanguages.contains("en"))||(uiLanguages.contains("en-US")))
        {
            //查找MAP中是否有英文翻译文件
            for(auto iter = CTranslation::m_maptranslators.begin(); iter != CTranslation::m_maptranslators.end(); iter++)
            {
                if(iter.key() == EM_LANGUAGE_TYPE_ENGLISH)
                {
                    CTranslation::m_emLanguageType = EM_LANGUAGE_TYPE_ENGLISH;
                    if(QCoreApplication::instance()->installTranslator(iter.value().get()))
                    {
                        QLOG_INFO() << "install lauguage file:" << language_file_name[CTranslation::m_emLanguageType];
                        return;
                    }
                    else
                    {
                        QLOG_WARN() << "Failed to install lauguage file:" << language_file_name[CTranslation::m_emLanguageType];
                    }
                    return;
                }
            }
        }

        //如果没有找到系统语言对应的翻译文件，则使用第一个翻译文件
        CTranslation::m_emLanguageType = CTranslation::m_maptranslators.begin().key();
        QCoreApplication::instance()->installTranslator(CTranslation::m_maptranslators.begin().value().get());
        QLOG_INFO() << "install lauguage file:" << language_file_name[CTranslation::m_emLanguageType];
    }

    void CTranslation::ChangeLanguage(EM_LANGUAGE_TYPE emLanguageType)
    {
        if(emLanguageType == CTranslation::m_emLanguageType)
        {
            return;
        }

        if(emLanguageType == EM_LANGUAGE_TYPE_ENGLISH)
        {
            // 原本就是英文只需要卸载当前的翻译文件即可
            if(QCoreApplication::instance()->removeTranslator(CTranslation::m_maptranslators[CTranslation::m_emLanguageType].get()))
            {
                QLOG_INFO() << "install lauguage file:" << language_file_name[EM_LANGUAGE_TYPE_ENGLISH];
                CTranslation::m_emLanguageType = EM_LANGUAGE_TYPE_ENGLISH;
                emit CTranslation::Instance()->signal_change_language();
            }
            else
            {
                QLOG_WARN() << "Failed to remove lauguage file:" << language_file_name[CTranslation::m_emLanguageType];
            }
            return;
        }

        for(auto iter = CTranslation::m_maptranslators.begin(); iter != CTranslation::m_maptranslators.end(); iter++)
        {
            if(iter.key() == emLanguageType)
            {
                if(QCoreApplication::instance()->installTranslator(iter.value().get()))
                {
                    QLOG_INFO() << "install lauguage file:" << language_file_name[CTranslation::m_emLanguageType];
                    CTranslation::m_emLanguageType = emLanguageType;
                    emit CTranslation::Instance()->signal_change_language();
                    return;
                }
                else
                {
                    QLOG_WARN() << "Failed to install lauguage file:" << language_file_name[CTranslation::m_emLanguageType];
                    return;
                }
            }
        }

        //如果没有找到对应的翻译文件, 则不改变当前语言
        QLOG_WARN() << "No language files are loaded.";
    }
}
