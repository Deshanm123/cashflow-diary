#include "user.h"

User::User(int userId, QString userName, QString password)
{
   this->userId =userId;
   this->userName = userName;
   this->password = password;
}

User::User()
{
    this->userId =NULL;
    this->userName = " ";
     this->password = " ";
}

int User::getUserId() const
{
    return userId;
}

void User::setUserId(int newUserId)
{
    userId = newUserId;
}

const QString &User::getUserName() const
{
    return userName;
}

void User::setUserName(const QString &newUserName)
{
    userName = newUserName;
}

const QString &User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &newPassword)
{
    password = newPassword;
}
