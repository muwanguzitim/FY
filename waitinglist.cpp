#include "waitinglist.h"
#include "ui_waitinglist.h"
#include "dialog.h"
#include "doctor.h"

WaitingList::WaitingList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitingList)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

WaitingList::~WaitingList()
{
    delete ui;
}

void WaitingList::on_pushButton_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from queue");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());
}

void WaitingList::on_pushButton_2_clicked()
{
    this->hide();
    Doctor mySP;
    mySP.setModal(true);
    mySP.exec();
}
