#include "users_admin.h"
#include "ui_users_admin.h"
#include "dialog.h"
#include "QMessageBox"
#include <QCryptographicHash>

Users_Admin::Users_Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users_Admin)
{
    ui->setupUi(this);


    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

   // ui->comboBox->addItem("");

}

Users_Admin::~Users_Admin()
{
    delete ui;
}

void Users_Admin::on_pushButton_clicked()
{
    Dialog conn;
    QString FN,LN,UN,P,R;
    FN=ui->lineEdit->text();
    LN=ui->lineEdit_2->text();
    UN=ui->lineEdit_3->text();
    P=ui->lineEdit_4->text();
    R=ui->lineEdit_5->text();

    QString queryStr;
    queryStr = QString("%1").arg(QString(QCryptographicHash::hash(ui->lineEdit_4->text().toUtf8(),QCryptographicHash::Md5).toHex()));

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into login (firstname,lastname,username,password,role) "
                "values('"+FN+"','"+LN+"','"+UN+"','"+queryStr+"','"+R+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Added"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

/*void Users_Admin::on_comboBox_activated(const QString &arg1)
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select Role from roles");

    qry->exec();
    model->setQuery(*qry);
    ui->comboBox->setModel(model);
}*/

void Users_Admin::on_pushButton_2_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from signup");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());
}
