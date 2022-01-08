#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <user.h>

class DbManager
{
public:
    DbManager();
    bool addUser(const QString& userName,const QString& password);
    User loginUser(const QString& userName,const QString& password);
private:
   QSqlDatabase m_db;
};

#endif // DBMANAGER_H
