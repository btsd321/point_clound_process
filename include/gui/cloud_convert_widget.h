#ifndef CLOUD_CONVERT_WIDGET_H
#define CLOUD_CONVERT_WIDGET_H

#include <QWidget>

#include "./ui_cloud_convert_widget.h"

namespace Ui {
class CCloudConvertWidget;
}

namespace btsd
{
    class CCloudConvertWidget : public QWidget
    {
        Q_OBJECT

    public:
        explicit CCloudConvertWidget(QWidget *parent = nullptr);
        ~CCloudConvertWidget();

        void paintEvent(QPaintEvent *event) override;
    signals:
        void signal_return_home();

    private slots:
        void on_pB_return_clicked();

    private:
        Ui::CCloudConvertWidget *ui;
    };

}

#endif // CLOUD_CONVERT_WIDGET_H
