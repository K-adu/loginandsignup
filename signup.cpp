#include "signup.h"
#include "ui_signup.h"
#include<QtSql>
#include<QMessageBox>
signup::signup(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::signup)
{
  ui->setupUi(this);
  QPixmap pix("C:/Users/manish baral/Desktop/project pictures/47216017");
  ui->s_labelbackground->setPixmap(pix.scaled(900,900));

}

signup::~signup()
{
  delete ui;
}

void signup::on_s_pushbuttonsignup_clicked()
{
  QString servername ="DESKTOP-ID7MOAE\\TINYSQL";
    QString mydbname ="fitnessfirst";
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QODBC");
    mydb.setConnectOptions();

    QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(mydbname);
    mydb.setDatabaseName(dsn);

    QString username, password,firstname,lastname;
    QString gender;
    QString age;
        firstname = ui->s_lineeditfirstname->text();
        lastname = ui->s_lineeditlastname->text();
        username = ui->s_lineeditusername->text();
        password = ui->s_lineeditpassword->text();

        age= ui->s_lineeditage->text();
        gender = ui->s_lineeditgender->text();

        if(!mydb.open())
        {
            qDebug() << "Failed to open the database";
            return ;
        }

        QSqlQuery qry(mydb);

        QString stmt = "select * from login where Username='"+ username +"'";

        if( qry.exec(stmt))
        {
            int count = 0;

            while(qry.next())
                count++;
            if( count < 1 ){
                qry.exec("INSERT INTO dbo.login (Username,Password,Firstname,Lastname,Age) VALUES('"+username+"','"+password+"','"+firstname+"','"+lastname+"','"+age+"');");

                QMessageBox::information(this,"Welcome","Your Record are Registered");

                hide();
              }

            if( count == 1 || count > 1 )
                QMessageBox::information(this,"Sorry!","One or more of the information matches to other user or is incorrect");
        }

}
