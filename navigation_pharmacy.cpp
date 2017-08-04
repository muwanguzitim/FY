#include "navigation_pharmacy.h"
#include "ui_navigation_pharmacy.h"

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
#include "pharmacy_newstock.h"

Navigation_Pharmacy::Navigation_Pharmacy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation_Pharmacy)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Navigation_Pharmacy::~Navigation_Pharmacy()
{
    delete ui;
}

void Navigation_Pharmacy::on_pushButton_5_clicked()
{
    Pharmacy myPharm;
    myPharm.setModal(true);
    myPharm.exec();
}

void Navigation_Pharmacy::on_pushButton_7_clicked()
{
    Invoice myPharm;
    myPharm.setModal(true);
    myPharm.exec();
}

void Navigation_Pharmacy::on_pushButton_8_clicked()
{
    Appointments myPharm;
    myPharm.setModal(true);
    myPharm.exec();
}


void Navigation_Pharmacy::on_pushButton_clicked()
{
    this->hide();
    Dialog myPharm;
    myPharm.setModal(true);
    myPharm.exec();
}

void Navigation_Pharmacy::on_pushButton_2_clicked()
{
    Pharmacy_newstock myPharm;
    myPharm.setModal(true);
    myPharm.exec();

}
