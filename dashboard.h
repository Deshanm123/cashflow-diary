#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include<QCalendarWidget>
namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT


public:
   //creating a constructor with user id with constructor overloading
     Dashboard(QWidget *parent=nullptr , const QString user= " ");
//    explicit Dashboard(QWidget *parent = nullptr);
     QCalendarWidget  *calender;

    ~Dashboard();
private slots:
     void on_calendarWidget_clicked(const QDate &date);

     void on_addTransBtn_clicked();

private:
      QString selectedDate;

    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
