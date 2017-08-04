#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QtSql>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);





}

MainWindow::~MainWindow()
{
    delete ui;
}


