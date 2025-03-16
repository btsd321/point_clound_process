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
        QTranslator translator;
        const QStringList uiLanguages = QLocale::system().uiLanguages();
        QLOG_INFO() << "System language:" << uiLanguages;

        // 查找语言文件
        if (uiLanguages.contains("zh_CN"))
        {
            CTranslation::m_emLanguageType = EM_LANGUAGE_TYPE_CHINESE;
        }
        else if (uiLanguages.contains("en"))
        {
            CTranslation::m_emLanguageType = EM_LANGUAGE_TYPE_ENGLISH;
        }
        else
        {
            qWarning() << "Not support language:" << uiLanguages << ", use default language zh_CN.";
            CTranslation::m_emLanguageType = EM_LANGUAGE_TYPE_CHINESE;
        }

        QString baseName;
        if(CTranslation::m_emLanguageType == EM_LANGUAGE_TYPE_CHINESE)
        {
            baseName = QString("point_clound_process_zh_CN.qm");
        }
        else if(CTranslation::m_emLanguageType == EM_LANGUAGE_TYPE_ENGLISH)
        {
            baseName = QString("point_clound_process_en_AS.qm");
        }

        QString file_path = QString(TRANSLATION_FLODER_NAME);

        if (translator.load(file_path + "/" + baseName))
        {
            QApplication::instance()->installTranslator(&translator);
            QLOG_INFO() << "install lauguage file:" << baseName;
        }
    }

    void CTranslation::ChangeLanguage(EM_LANGUAGE_TYPE emLanguageType)
    {
        if(emLanguageType == CTranslation::m_emLanguageType)
        {
            return;
        }

        CTranslation::m_emLanguageType = emLanguageType;
        QTranslator translator;
        QString baseName;
        if(CTranslation::m_emLanguageType == EM_LANGUAGE_TYPE_CHINESE)
        {
            baseName = QString("point_clound_process_zh_CN.qm");
            QLOG_INFO() << "Change language to Chinese.";
        }
        else if(CTranslation::m_emLanguageType == EM_LANGUAGE_TYPE_ENGLISH)
        {
            baseName = QString("point_clound_process_en_AS.qm");
            QLOG_INFO() << "Change language to English.";
        }

        QString file_path = QString(TRANSLATION_FLODER_NAME);

        if (translator.load(file_path + "/" + baseName))
        {
            QApplication::instance()->installTranslator(&translator);
        }

        emit CTranslation::Instance()->signal_change_language();
    }
}
