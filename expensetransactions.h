#ifndef EXPENSETRANSACTIONS_H
#define EXPENSETRANSACTIONS_H

#include "transactionsabstractclass.h"
#include <QObject>

class expenseTransactions : public TransactionsAbstractClass
{
public:
    expenseTransactions();
    void addTransaction();
};

#endif // EXPENSETRANSACTIONS_H
