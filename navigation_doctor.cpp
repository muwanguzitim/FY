#include "navigation_doctor.h"
#include "ui_navigation_doctor.h"
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

Navigation_doctor::Navigation_doctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation_doctor)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Navigation_doctor::~Navigation_doctor()
{
    delete ui;
}

void Navigation_doctor::on_pushButton_2_clicked()
{

    Doctor myDoc;
    myDoc.setModal(true);
    myDoc.exec();
}

void Navigation_doctor::on_pushButton_7_clicked()
{
    Invoice myInv;
    myInv.setModal(true);
    myInv.exec();
}

void Navigation_doctor::on_pushButton_8_clicked()
{
    Appointments myAppoint;
    myAppoint.setModal(true);
    myAppoint.exec();
}

void Navigation_doctor::on_pushButton_clicked()
{
    this->hide();
    Dialog myAppoint;
    myAppoint.setModal(true);
    myAppoint.exec();
}
