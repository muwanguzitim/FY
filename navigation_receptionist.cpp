#include "navigation_receptionist.h"
#include "ui_navigation_receptionist.h"

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
#include "appointment_receptionist.h"

Navigation_receptionist::Navigation_receptionist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation_receptionist)
{
    ui->setupUi(this);


    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Navigation_receptionist::~Navigation_receptionist()
{
    delete ui;
}

void Navigation_receptionist::on_pushButton_clicked()
{
    SearchPatient mySP;
    mySP.setModal(true);
    mySP.exec();
}

void Navigation_receptionist::on_pushButton_15_clicked()
{
    Invoice myInv;
    myInv.setModal(true);
    myInv.exec();
}

void Navigation_receptionist::on_pushButton_16_clicked()
{
    Appointment_receptionist myAppoint;
    myAppoint.setModal(true);
    myAppoint.exec();
}

void Navigation_receptionist::on_pushButton_2_clicked()
{
    this->hide();
    Dialog myAppoint;
    myAppoint.setModal(true);
    myAppoint.exec();
}
