#include <QStyleOption>
#include <QPainter>
#include <QFileDialog>
#include <QFile>
#include "gui/cloud_convert_widget.h"
#include "app/translation.h"

namespace btsd
{
    CCloudConvertWidget::CCloudConvertWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::CCloudConvertWidget)
    {
        ui->setupUi(this);

        connect(CTranslation::Instance(), &CTranslation::signal_change_language, this, &CCloudConvertWidget::slot_change_language);
    }

    CCloudConvertWidget::~CCloudConvertWidget()
    {
        delete ui;
    }

    void CCloudConvertWidget::paintEvent(QPaintEvent *event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }

    void CCloudConvertWidget::on_pB_return_clicked()
    {
        emit signal_return_home();
    }

    void CCloudConvertWidget::slot_change_language()
    {
        ui->retranslateUi(this);
    }

    void CCloudConvertWidget::on_pb_input_brose_clicked()
    {
        // Open file dialog
        QFile file_input_cloud = QFileDialog::getOpenFileName(
            this,                                                       // 父窗口
            tr("Open Point Cloud File"), //"打开点云文件"                // 对话框标题
            QCoreApplication::instance()->applicationDirPath(),         // 起始路径
            tr("Text Point Cloud File (*.txt);;Binary Point Cloud File (*.bin);;PLY Point Cloud File (*.ply);;PCD Point Cloud File (*.pcd)"),
            //tr("文本点云文件 (*.txt);;二进制点云文件 (*.bin);;PLY点云文件 (*.ply);;PCD点云文件 (*.pcd)"),     // 文件过滤器
            nullptr,                                                    // 存储用户选择的文件过滤器
            QFileDialog::DontUseNativeDialog                            // 选项
        );
        // 将文件路径显示在文本框le_inpu_cloud_path中
        ui->le_input_cloud_path->setText(file_input_cloud.fileName());
    }

}

