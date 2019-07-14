#include "login.h"
#include "ui_login.h"
#include<QtSql>
#include<QMessageBox>
#include"homepage.h"
Login::Login(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Login)
{
  ui->setupUi(this);
  QPixmap pix("C:/Users/manish baral/Desktop/project pictures/BM");
  ui->l_labelbackground->setPixmap(pix.scaled(900,500));
}

Login::~Login()
{
  delete ui;
}

void Login::on_l_pushbuttonlogin_clicked()
{
  QString servername ="DESKTOP-ID7MOAE\\TINYSQL";
   QString dbname ="fitnessfirst";
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setConnectOptions();
   QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);
   db.setDatabaseName(dsn);
   QString username, password;
       username = ui->l_lineeditusername->text();
       password = ui->l_lineeditpassword->text();

       if(!db.open())
       {
           qDebug() << "Failed to open the database";
           return ;
       }

       QSqlQuery qry(db);
       QString stmt = "select * from login where Username='"+ username +"' and Password='"+ password +"'";

       if( qry.exec(stmt))
       {
           int count = 0;
           while(qry.next())
               count++;
           if( count == 1 ){
               hide();

               this->hide();
               homepage = new homePage(this);
               homepage->show();


             }

           if( count < 1 )
               QMessageBox::information(this,"Sorry!","Username and Password mismatch...");
       }
       else
       {
           qDebug() << qry.lastError();
       }

}

void Login::on_l_pushbuttonsignup_clicked()
{
  s = new signup(this);
  s->show();




}

void Login::on_exercise_pushbutton_clicked()
{

}
void Login::on_diet_pushbutton_clicked()
{

}

