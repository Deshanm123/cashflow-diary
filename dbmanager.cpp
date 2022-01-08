
#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <user.h>


DbManager::DbManager()
{
    QString path = "C:\\Users\\USER\\Desktop\\sql-lite-practice\\test-sql-lite.db";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}
User DbManager::loginUser(const QString& userName,const QString& password){
//   User 
     User *user =new User();
    QSqlQuery loginQry;
    QString loginQryStr="SELECT * FROM usertb WHERE userName = (:userName) AND password = (:password)";
    loginQry.prepare(loginQryStr);
    loginQry.bindValue(":userName",userName);
    loginQry.bindValue(":password",password);
    if(loginQry.exec()){
        while(loginQry.next()){
            QString nameFromDb = loginQry.value(1).toString();
            QString passFromDb = loginQry.value(2).toString();
            int idFromDb  = loginQry.value(0).toInt();
//             instantiating the  user that corresponds to input credentials
            if (userName == nameFromDb && password==passFromDb){
                user->setUserId(idFromDb);
                user->setUserName(nameFromDb);
                user->setPassword(passFromDb);
             }
        }
    }
    return *user;
}

//insert user transcation
bool DbManager::addUser(const QString& userName,const QString& password)
{
   bool status = false;
    QSqlQuery insertQry;
    QString insertQryStr = "INSERT INTO usertb(userName,password) VALUES (:userName,:password)";
    insertQry.prepare(insertQryStr);
//        binding values
    insertQry.bindValue(":userName",userName);
    insertQry.bindValue(":password",password);

    if(insertQry.exec()){
      status=true;
    }
    return status;
}
