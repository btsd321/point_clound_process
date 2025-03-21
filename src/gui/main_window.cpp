﻿#include <QActionGroup>
#include "gui/main_window.h"
#include "app/translation.h"


namespace btsd
{
    CMainWindow::CMainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::CMainWindow)
    {
        ui->setupUi(this);
        ui->stacked_widget->setCurrentIndex(EM_WIDGET_ID_HOME);

        menuBar()->removeAction(ui->action_chinese);
        menuBar()->removeAction(ui->action_english);

        QActionGroup *langGroup = new QActionGroup(this);
        langGroup->addAction(ui->action_chinese);
        langGroup->addAction(ui->action_english);
        langGroup->setExclusive(true);

        connect(CTranslation::Instance(), &CTranslation::signal_change_language, this, &CMainWindow::slot_change_language);
        connect(ui->page_c1s1_1, &CCloudConvertWidget::signal_return_home, this, &CMainWindow::slot_return_home);
    }

    
    CMainWindow::~CMainWindow()
    {
        delete ui;
    }

    void CMainWindow::on_action_chinese_triggered()
    {
        CTranslation::Instance()->ChangeLanguage(EM_LANGUAGE_TYPE_CHINESE);
    }

    void CMainWindow::on_action_english_triggered()
    {
        CTranslation::Instance()->ChangeLanguage(EM_LANGUAGE_TYPE_ENGLISH);
    }

    void CMainWindow::slot_change_language()
    {
        ui->retranslateUi(this);
    }

    void CMainWindow::slot_return_home()
    {
        ui->stacked_widget->setCurrentIndex(EM_WIDGET_ID_HOME);
    }

    void CMainWindow::on_action_c1s1_1_triggered()
    {
        ui->stacked_widget->setCurrentIndex(EM_WIDGET_ID_C1S1_1);
    }




}
