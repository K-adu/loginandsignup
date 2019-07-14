#include "homepage.h"
#include "ui_homepage.h"

homePage::homePage(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::homePage)
{
  ui->setupUi(this);
}

homePage::~homePage()
{
  delete ui;
}
