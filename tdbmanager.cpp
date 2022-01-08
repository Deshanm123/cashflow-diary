#include "tdbmanager.h"
#include <QDebug>
#include <QSqlQuery>
tDbManager::tDbManager()
{
    QString path = "C:\\Users\\USER\\Desktop\\sql-lite-practice\\test-sql-lite.db";
       m_tdb = QSqlDatabase::addDatabase("QSQLITE");
       m_tdb.setDatabaseName(path);

       if (!m_tdb.open())
       {
           qDebug() << "Error: connection with database fail";
       }
       else
       {
           qDebug() << "Database: connection ok";
       }
}

//bool tDbManager::viewTransactionsFromDb(QString tableType)
//{

//}

bool tDbManager::addTransactionToDb(QString transactionName,QString transactionType,QString transactionDate,QString transactionCategory,double transactionAmount)
{
        bool status=false;
        QSqlQuery addTransactionQry;
        QString addTransactionQryStr;
        if(transactionType=="income"){
             addTransactionQryStr ="NSERT INTO incomeTransactionstb(transName,transDate,transCategory,transAmount) VALUES (:transactionName,:transactionDate,:transactionCategory,:transactionAmount);";
        }else{
            addTransactionQryStr  ="NSERT INTO expenseTransactionstb(transName,transDate,transCategory,transAmount) VALUES (:transactionName,:transactionDate,:transactionCategory,:transactionAmount);";
        }
        addTransactionQry.prepare(addTransactionQryStr);
        addTransactionQry.bindValue(":transactionName",transactionName);
        addTransactionQry.bindValue(":transactionDate",transactionDate);
        addTransactionQry.bindValue(":transactionCategory",transactionCategory);
        addTransactionQry.bindValue(":transactionAmount",transactionAmount);
        if(addTransactionQry.exec()){
          status= true;
        }
        return status;
}
