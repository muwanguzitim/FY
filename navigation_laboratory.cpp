#include "navigation_laboratory.h"
#include "ui_navigation_laboratory.h"

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

Navigation_Laboratory::Navigation_Laboratory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation_Laboratory)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Navigation_Laboratory::~Navigation_Laboratory()
{
    delete ui;
}

void Navigation_Laboratory::on_pushButton_4_clicked()
{
    Laboratory myLab;
    myLab.setModal(true);
    myLab.exec();
}

void Navigation_Laboratory::on_pushButton_7_clicked()
{
    Invoice myInv;
    myInv.setModal(true);
    myInv.exec();
}

void Navigation_Laboratory::on_pushButton_8_clicked()
{
    Appointments myA;
    myA.setModal(true);
    myA.exec();
}

void Navigation_Laboratory::on_pushButton_clicked()
{
    this->hide();
    Dialog myA;
    myA.setModal(true);
    myA.exec();
}
