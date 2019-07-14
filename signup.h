#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>

namespace Ui {
  class signup;
}

class signup : public QMainWindow
{
  Q_OBJECT

public:
  explicit signup(QWidget *parent = nullptr);
  ~signup();

private slots:
  void on_s_pushbuttonsignup_clicked();

private:
  Ui::signup *ui;
};

#endif // SIGNUP_H
