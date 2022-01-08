#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QString>

class User
{
public:
//    constructors
    User(int userId,QString userName,QString password);
    User();
    //gettersand setters
    int getUserId() const;
    void setUserId(int newUserId);

    const QString &getUserName() const;
    void setUserName(const QString &newUserName);

    const QString &getPassword() const;
    void setPassword(const QString &newPassword);

private:
    int userId;
    QString userName;
    QString password;

};

#endif // USER_H
