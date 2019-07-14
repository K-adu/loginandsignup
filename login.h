#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include"signup.h"
#include"homepage.h"
namespace Ui {
  class Login;
}

class Login : public QMainWindow
{
  Q_OBJECT

public:
  explicit Login(QWidget *parent = nullptr);
  ~Login();

private slots:
  void on_l_pushbuttonlogin_clicked();

  void on_l_pushbuttonsignup_clicked();
  void on_exercise_pushbutton_clicked();
  void on_diet_pushbutton_clicked();
  void on_pushButton_clicked();

private:
  Ui::Login *ui;
  signup *s;
  homePage *homepage;
};

#endif // LOGIN_H
