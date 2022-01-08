#include "dashboard.h"
#include "ui_dashboard.h"
#include <QMessageBox>
#include <transcationentry.h>

//Dashboard::Dashboard(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::Dashboard)
//{
//    ui->setupUi(this);
//}

Dashboard::Dashboard(QWidget *parent, const QString user):
    QDialog(parent),
    ui(new Ui::Dashboard)
{
     ui->setupUi(this);
    ui->label_2->setText(user);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_calendarWidget_clicked(const QDate &date)
{
//    QDate selectedDate = &date;
 selectedDate =date.toString("yyyy.MM.dd");
QMessageBox::information(this,"date",selectedDate);
}


void Dashboard::on_addTransBtn_clicked()
{
    TranscationEntry *transactionEntryForm = new  TranscationEntry();
    transactionEntryForm->setModal(true);
    transactionEntryForm->exec();
}

