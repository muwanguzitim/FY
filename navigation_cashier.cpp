#include "navigation_cashier.h"
#include "ui_navigation_cashier.h"

#include <QtSql>
#include "receiptionist.h"
#include "doctor.h"
#include "laboratory.h"
#include "pharmacy.h"
#include "cashier.h"
#include "invoice.h"
#include "appointments.h"
#include <QAction>
#include <QActionEvent>
#include "triage.h"
#include "admin.h"
#include "searchpatient.h"
#include "dialog.h"

Navigation_Cashier::Navigation_Cashier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation_Cashier)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Navigation_Cashier::~Navigation_Cashier()
{
    delete ui;
}

void Navigation_Cashier::on_pushButton_6_clicked()
{
    Cashier myCash;
    myCash.setModal(true);
    myCash.exec();
}


void Navigation_Cashier::on_pushButton_7_clicked()
{
    Invoice myInv;
    myInv.setModal(true);
    myInv.exec();
}

void Navigation_Cashier::on_pushButton_clicked()
{
    this->hide();
    Dialog myAppoint;
    myAppoint.setModal(true);
    myAppoint.exec();
}

void Navigation_Cashier::on_pushButton_2_clicked()
{
    Appointments myAppoint;
    myAppoint.setModal(true);
    myAppoint.exec();
}
