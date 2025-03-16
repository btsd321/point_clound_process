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
    typedef enum ENUM_WIDGET_ID
    {
        EM_WIDGET_ID_HOME = 0,
        EM_WIDGET_ID_C1S1_1,
        EM_WIDGET_ID_MAX
    }EM_WIDGET_ID;

    class CMainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        CMainWindow(QWidget *parent = nullptr);
        ~CMainWindow();

    private slots:

        void on_action_chinese_triggered();

        void on_action_english_triggered();

        void on_action_c1s1_1_triggered();

    public slots:
        void slot_change_language();
        void slot_return_home();

    private:
        Ui::CMainWindow *ui;
    };
}
#endif // MAIN_WINDOW_H
