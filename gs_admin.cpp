#include "gs_admin.h"
#include "ui_gs_admin.h"
#include "dialog.h"

GS_Admin::GS_Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GS_Admin)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GS_Admin::~GS_Admin()
{
    delete ui;
}

void GS_Admin::on_pushButton_3_clicked()
{
    Dialog conn;
    QString HN,SY,OPN,C,E;
    HN=ui->txt_hn->text();
    SY=ui->txt_sy->text();
    OPN=ui->txt_opn->text();
    C=ui->txt_c->text();
    E=ui->txt_e->text();


    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into generalSettings (HospitalName,StartingYear,OfficePhoneNo,Country,Email) "
                "values('"+HN+"','"+SY+"','"+OPN+"','"+C+"','"+E+"')");

    qry.exec();

}
