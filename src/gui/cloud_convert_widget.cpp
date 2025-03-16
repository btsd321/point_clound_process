#include <QStyleOption>
#include <QPainter>
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

}

