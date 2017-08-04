#include "admin.h"
#include "ui_admin.h"
#include "gs_admin.h"
#include "users_admin.h"
#include "viewusers_admin.h"
#include "prescription_admin.h"
#include "medicine_admin.h"
#include "appointments.h"
#include "invoice.h"
#include "dialog.h"
#include "report.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    this->hide();
    Dialog myNav;
    myNav.setModal(true);
    myNav.exec();
}

void Admin::on_pushButton_2_clicked()
{
    GS_Admin myGS;
    myGS.setModal(true);
    myGS.exec();
}

void Admin::on_pushButton_6_clicked()
{
    Users_Admin myMU;
    myMU.setModal(true);
    myMU.exec();
}

void Admin::on_pushButton_5_clicked()
{
    ViewUsers_Admin myVU;
    myVU.setModal(true);
    myVU.exec();
}

void Admin::on_pushButton_10_clicked()
{
    Prescription_Admin myPres;
    myPres.setModal(true);
    myPres.exec();
}


void Admin::on_pushButton_12_clicked()
{
    Medicine_Admin myMed;
    myMed.setModal(true);
    myMed.exec();
}


void Admin::on_pushButton_4_clicked()
{
    Appointments myMed;
    myMed.setModal(true);
    myMed.exec();
}

void Admin::on_pushButton_3_clicked()
{
    Report myMed;
    myMed.setModal(true);
    myMed.exec();
}
