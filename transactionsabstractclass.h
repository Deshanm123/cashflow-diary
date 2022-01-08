#ifndef TRANSACTIONSABSTRACTCLASS_H
#define TRANSACTIONSABSTRACTCLASS_H
#include <QString>
#include <QDate>

class TransactionsAbstractClass
{
public:
    TransactionsAbstractClass();
    virtual void viewTransactions();
    virtual void addTransaction();
    virtual void updateTransction();
    virtual void removeTransaction();

////    setters and getters
//    int getTransactionId() const;
//    void setTransactionId(int newTransactionId);

//    const QString &getTransactionName() const;
//    void setTransactionName(const QString &newTransactionName);

//    const QString &getTransactionType() const;
//    void setTransactionType(const QString &newTransactionType);

//    const QDate &getTransactionDate() const;
//    void setTransactionDate(const QDate &newTransactionDate);

//    const QString &getTransactionCategory() const;
//    void setTransactionCategory(const QString &newTransactionCategory);

//    double getTransactionAmount() const;
//    void setTransactionAmount(double newTransactionAmount);

protected :
    int transactionId;
    QString transactionName;
    QString transactionType;
    QDate transactionDate;
    QString transactionCategory;
    double transactionAmount;

};

#endif // TRANSACTIONSABSTRACTCLASS_H
