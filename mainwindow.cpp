#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dbmanager.h>
#include <dashboard.h>

//for hashing password
 #include <QCryptographicHash>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->userNameLEdit->setPlaceholderText("Enter User Name");
    ui->passwordLEdit->setPlaceholderText("Enter password");
    ui->cpasswordLEdit->setPlaceholderText("Enter password again");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_registerBtn_clicked()
{
    DbManager db;

//  check  inputs are empty
if(!(ui->userNameLEdit->text().isEmpty() || ui->passwordLEdit->text().isEmpty())){
    ////    retrieve data from input fields
        QString userName = ui->userNameLEdit->text();
        QString password = ui->passwordLEdit->text();
      QString cPassword = ui->cpasswordLEdit->text();

//       password encryption md5 hashing
        QCryptographicHash cryptoHashMd5(QCryptographicHash::Md5);
        cryptoHashMd5.addData(password.toLatin1());
        QString encryptedPassword= cryptoHashMd5.result().toHex().data();

//passsing values to database
    if(db.addUser(userName,encryptedPassword)){
        QMessageBox::information(this,"status","transaction recorded  sucessfully");
    }else{
         QMessageBox::information(this," error status","transaction failed");
    }
}else{
    ui->statusbar->showMessage("please fill inputs",2000);
}

}


void MainWindow::on_loginBtn_clicked()
{
    DbManager db;
    //  check  inputs are empty
    if(!(ui->lUserNameLEdit->text().isEmpty() || ui->lPasswordLEdit->text().isEmpty())){
        ////    retrieve data from input fields
       QString lUserName = ui->lUserNameLEdit->text();
       QString lPassword = ui->lPasswordLEdit->text();

       //    password encryption md5 hashing
      QCryptographicHash cryptoHashMd5(QCryptographicHash::Md5);
      cryptoHashMd5.addData(lPassword.toLatin1());
       QString encryptedLPassword= cryptoHashMd5.result().toHex().data();

       User res = db.loginUser(lUserName,encryptedLPassword);
       int resId =res.getUserId();
       if(!(resId == NULL)){
//           QMessageBox::information(this,"welcome",res);
//           login to dashboard
           Dashboard *dashboard= new Dashboard(this,res.getUserName());
           dashboard->setModal(true);
           dashboard->exec();
        }else{
           QMessageBox::warning(this,"welcome","Invalid Credentials");
        }

    }else{
        ui->statusbar->showMessage("please fill login inputs",2000);
    }

}

