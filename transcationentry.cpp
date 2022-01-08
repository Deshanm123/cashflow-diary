#include "transcationentry.h"
#include "ui_transcationentry.h"
#include <QString>
#include <incometransactions.h>
#include <tdbmanager.h>

TranscationEntry::TranscationEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TranscationEntry)
{
    ui->setupUi(this);
}

TranscationEntry::~TranscationEntry()
{
    delete ui;
}


void TranscationEntry::on_doneBtn_clicked()
{
    QString transName = ui->transNameLEdit->text();
    QString transAmount = ui->transAmountLEdit->text();
    QString transDate=ui->transDateLEdit->text();
    QString transCategory = ui->transCategoryLEdit->text();
    double  transAmountDouble = transAmount.toDouble();
    tDbManager  transaction ;
    transaction.addTransactionToDb(transName, "expense",transDate, transCategory, transAmountDouble);



}

