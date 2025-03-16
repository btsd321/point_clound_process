#include <iostream>
#include <Windows.h>

#include <QDir>
#include "gui/main_window.h"

#include "app/translation.h"
#include "app/log.h"
#include "common/global.h"
#include "main.h"

namespace btsd
{
    static void LoadConfig()
    {
        QLOG_INFO() << "尝试载入设置...";

        // 检查设置目录是否存在，不存在则创建
        QString strConfigDir = CONFIG_FLODER_NAME;
        QDir dir(QApplication::instance()->applicationDirPath() + "/" + strConfigDir);
        if (!dir.exists())
        {
            QLOG_INFO() << "设置目录不存在，创建目录";
            dir.mkpath(".");
        }
    }

    void logFunction(const QString &message, QsLogging::Level level)
    {
        std::cout << "From log function: " << qPrintable(message) << " " << static_cast<int>(level)
        << std::endl;
    }
}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    QApplication app(argc, argv);
    //日志初始化
    btsd::CLogFunction::Init();
    //翻译初始化
    btsd::CTranslation::Init();
    //设置初始化
    btsd::LoadConfig();
    //窗口初始化
    btsd::CMainWindow w;
    w.show();
    return QApplication::instance()->exec();
}
