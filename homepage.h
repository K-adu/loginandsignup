#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>

namespace Ui {
  class homePage;
}

class homePage : public QMainWindow
{
  Q_OBJECT

public:
  explicit homePage(QWidget *parent = nullptr);
  ~homePage();

private:
  Ui::homePage *ui;
};

#endif // HOMEPAGE_H
