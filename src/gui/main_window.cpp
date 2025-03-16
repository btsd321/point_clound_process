#include <QActionGroup>
#include "gui/main_window.h"
#include "app/translation.h"


namespace btsd
{
    CMainWindow::CMainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::CMainWindow)
    {
        ui->setupUi(this);

        menuBar()->removeAction(ui->action_chinese);
        menuBar()->removeAction(ui->action_english);

        QActionGroup *langGroup = new QActionGroup(this);
        langGroup->addAction(ui->action_chinese);
        langGroup->addAction(ui->action_english);
        langGroup->setExclusive(true);

        connect(CTranslation::Instance(), SIGNAL(signal_change_language()), this, SLOT(slot_change_language()));

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


}
