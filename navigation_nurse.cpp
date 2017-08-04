#include "navigation_nurse.h"
#include "ui_navigation_nurse.h"
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

Navigation_nurse::Navigation_nurse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation_nurse)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Navigation_nurse::~Navigation_nurse()
{
    delete ui;
}

void Navigation_nurse::on_pushButton_3_clicked()
{
    Triage myTr;
    myTr.setModal(true);
    myTr.exec();
}

void Navigation_nurse::on_pushButton_7_clicked()
{
    Invoice myTr;
    myTr.setModal(true);
    myTr.exec();
}

void Navigation_nurse::on_pushButton_8_clicked()
{
    Appointments myTr;
    myTr.setModal(true);
    myTr.exec();
}

void Navigation_nurse::on_pushButton_clicked()
{
    this->hide();
    Dialog myA;
    myA.setModal(true);
    myA.exec();
}
