#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "./ui_main_window.h"
#include "common/DataType.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CMainWindow;
}
QT_END_NAMESPACE

namespace btsd
{
    class CMainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        CMainWindow(QWidget *parent = nullptr);
        ~CMainWindow();

    private slots:

        void on_action_chinese_triggered();

        void on_action_english_triggered();

    public slots:
        void slot_change_language();

    private:
        Ui::CMainWindow *ui;
    };
}
#endif // MAIN_WINDOW_H
