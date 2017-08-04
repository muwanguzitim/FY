#include "admin_login.h"
#include "ui_admin_login.h"
#include "admin.h"
#include <QtSql>
#include "dialog.h"
#include <QMessageBox>

Admin_login::Admin_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_login)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Admin_login::~Admin_login()
{
    delete ui;
}

void Admin_login::on_pushButton_2_clicked()
{
    Dialog conn;
    QString firstname,lastname,username,password,role;
    firstname=ui->txt_firstname->text();
    lastname=ui->txt_lastname->text();
    username=ui->txt_username1->text();
    password=ui->txt_password1->text();
    role=ui->txt_Role->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into signup (firstname,lastname,username,password,role) "
                "values('"+firstname+"','"+lastname+"','"+username+"','"+password+"','"+role+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Sent"),tr("Your request has been sent"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void Admin_login::on_pushButton_clicked()
{
    this->hide();
    Dialog myDialog;
    myDialog.setModal(true);
    myDialog.exec();
}

void Admin_login::on_pushButton_3_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select Role from roles");

    qry->exec();
    model->setQuery(*qry);
    ui->comboBox->setModel(model);
}

void Admin_login::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString Role=ui->comboBox->currentText();

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select Role from roles where Role='"+Role+"'");

    if(qry.exec())

    {
        while (qry.next())
        {
            ui->txt_Role->setText(qry.value(0).toString());
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

