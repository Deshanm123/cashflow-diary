#ifndef TDBMANAGER_H
#define TDBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
class tDbManager
{
public:
    tDbManager();

//  bool viewTransactionsFromDb(QString tableType);
    bool addTransactionToDb(QString transactionName,QString transactionType,QString transactionDate,QString transactionCategory,double transactionAmount);
//    bool updateTransctionToDb();
//    bool  removeTransactionFromDb();
private:
    QSqlDatabase m_tdb;
};
#endif // TDBMANAGER_H
