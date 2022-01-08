#include "transactions.h"
#include <qdebug.h>

TransactionManager::TransactionManager()
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
