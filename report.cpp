#include "report.h"
#include "ui_report.h"
#include "dialog.h"
#include <QMessageBox>
#include <QTime>
#include "/home/tim/Downloads/qcustomplot/qcustomplot.h"


Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->comboBox->addItem("Malaria");
    ui->comboBox->addItem("HIV/Aids");
    ui->comboBox->addItem("Typhoid");
    ui->comboBox->addItem("Syphilis");
    ui->comboBox->addItem("Hepatitis B");


    ui->comboBox_2->addItem("2015");
    ui->comboBox_2->addItem("2016");

    ui->comboBox_4->addItem("Malaria");
    ui->comboBox_4->addItem("Typhoid");
    ui->comboBox_4->addItem("HIV/Aids");
    ui->comboBox_4->addItem("Syphilis");


    ui->tabWidget_2->tabBar()->setTabTextColor(0,Qt::white);
    ui->tabWidget_2->tabBar()->setTabTextColor(1,Qt::white);
    ui->tabWidget_2->tabBar()->setTabTextColor(2,Qt::white);



}

Report::~Report()
{
    delete ui;
}

void Report::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString P=ui->comboBox->currentText();

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select Period from report where Period='"+P+"'");

    if(qry.exec())

    {
        while (qry.next())
        {
            //ui->txt_View->setText(qry.value(0).toString());
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void Report::on_pushButton_clicked()
{
    QString disease,diseasex,idx,resd,occu,timefrom,timeto;
    disease=ui->comboBox->currentText();
    qDebug() << disease;
    diseasex=disease+" positive";
    timefrom=ui->from->text();
    timeto=ui->to->text();

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from laboratory where Result='"+diseasex+"' and Date >= '"+timefrom+"' and Date <='"+timeto+"'");
    int xmale=0, xfemale=0, xsingle=0, xmarried=0, xchristian=0, xmoslem=0;
    int countx = 0;

    if(qry.exec())
    {
        int numRows = qry.record().count()+1;
        qDebug() << numRows;
        QString residence[numRows];
        int residencex[numRows];
        QString occupation[numRows];
        int occupationx[numRows];
        while (qry.next())
        {
            idx=qry.value(0).toString();
            QSqlQuery qry1;
            qry1.prepare("select * from patient where PatientID='"+idx+"'");
            if(qry1.exec()){

                while (qry1.next())
                {
                    if(qry1.value(6).toString()=="M"){
                      xmale++;
                    }else{
                      xfemale++;
                    }
                    if(qry1.value(14).toString()=="Married"){
                      xmarried++;
                    }else{
                      xsingle++;
                    }
                    if(qry1.value(8).toString()=="Christian"){
                      xchristian++;
                    }else{
                      xmoslem++;
                    }
                    resd = qry1.value(7).toString();
                    occu = qry1.value(5).toString();
                    int key = 0;
                    qDebug() << "====" << resd;
                    for (int i = 0; i < numRows; i++)
                     {
                        if(resd == residence[i]){
                            int prevx  = residencex[i];
                            residencex[i] = prevx+1;
                            residence[i] = resd;
                            key++;
                         }else{
                            if(i==numRows-1){
                                if(key==0){
                                   residencex[countx] = 1;
                                   residence[countx] = resd;
                                }
                            }
                        }
                     }
                    for (int i = 0; i < numRows; i++)
                     {
                        if(occu == occupation[i]){
                            int prevy  = occupationx[i];
                            occupationx[i] = prevy+1;
                            occupation[i] = occu;
                            key++;
                         }else{
                            if(i==numRows-1){
                                if(key==0){
                                   occupationx[countx] = 1;
                                   occupation[countx] = occu;
                                }
                            }
                        }
                     }
                     countx++;
                }
            }
        }
        qDebug() << xmale;
        qDebug() << xfemale;
        qDebug() << xmarried;
        qDebug() << xsingle;
        qDebug() << xchristian;
        qDebug() << xmoslem;
        qDebug() << "------------------------------------";
        QString ret="", rety="";
        for (int i = 0; i < numRows; i++)
         {
           if(residence[i]!=""&&residence[i]!=" "){
               QString yre, yrex;
               yre = residence[i]+" : "+yrex.setNum(residencex[i]);
               ret = ret+yre+", ";
               qDebug() << yre;

           }
         }

        for (int i = 0; i < numRows; i++)
         {
           if(occupation[i]!=""&&occupation[i]!=" "){
               QString yrey, yrexy;
               yrey = occupation[i]+" : "+yrexy.setNum(occupationx[i]);
               rety = rety+yrey+", ";
               qDebug() << yrey;

           }
         }

        QString ymale, yfemale, ysingle, ymarried, ychristian, ymoslem;

        ui->label_12->setText(ymale.setNum(xmale));
        ui->label_3->setText(yfemale.setNum(xfemale));
        ui->label_15->setText(ysingle.setNum(xsingle));
        ui->label_16->setText(ymarried.setNum(xmarried));
        ui->label_13->setText(ychristian.setNum(xchristian));
        ui->label_14->setText(ymoslem.setNum(xmoslem));
        ui->label_18->setText(disease);
        ui->label_20->setText(ret);
        ui->label_21->setText(rety);



        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void Report::on_pushButton_2_clicked()
{
    QString disease,idx,date,itemname;
    date=ui->date->text();

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry,qry1;
    qry.prepare("select * from laboratory where Date='"+date+"'");

    int countx = 0;

    if(qry.exec())
    {
        int numRows = qry.record().count()+1;
        QString di[numRows];
        int dix[numRows];

        while (qry.next())
        {
            idx=qry.value(0).toString();
            disease=qry.value(3).toString();

            int key = 0;
              for (int i = 0; i < numRows; i++)
                     {
                        if(disease == di[i]){
                            int prevx  = dix[i];
                            dix[i] = prevx+1;
                            di[i] = disease;
                            key++;

                         }else{
                            if(i==numRows-1){
                                if(key==0){
                                   dix[countx] = 1;
                                   di[countx] = disease;
                                }
                            }
                        }

                     }
                   countx++;
        }
        QString ret="";
        for (int i = 0; i < numRows; i++)
         {
           if(di[i]!=""&&di[i]!=" "){
               QString yre, yrex;
               yre = di[i]+" : "+yrex.setNum(dix[i]);
               ret = ret+yre+", ";
           }
        ui->label_dix->setText(ret);


        }

        QSqlQueryModel* model = new QSqlQueryModel();

        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        {

        qry->prepare("select * from laboratory where Date='"+date+"'");

        qry->exec();
        model->setQuery(*qry);
        ui->tableView->setModel(model);

    }

    }
    qry1.prepare("select * from pharmacy where Date='"+date+"'");

    int county = 0;

    if(qry1.exec())
    {
        int numRows = qry1.record().count()+1;
        QString in[numRows];
        int inx[numRows];

        while (qry1.next())
        {
            itemname=qry1.value(2).toString();

            int key = 0;
              for (int i = 0; i < numRows; i++)
                     {
                        if(itemname == in[i]){
                            int prevx  = inx[i];
                            inx[i] = prevx+1;
                            in[i] = itemname;
                            key++;

                         }else{
                            if(i==numRows-1){
                                if(key==0){
                                   inx[county] = 1;
                                   in[county] = itemname;
                                }
                            }
                        }

                     }
                   county++;
        }
        QString rety="";
        for (int i = 0; i < numRows; i++)
         {
           if(in[i]!=""&&in[i]!=" "){
               QString yrey, yrexy;
               yrey = in[i]+" : "+yrexy.setNum(inx[i]);
               rety = rety+yrey+", ";
           }
        ui->label_28->setText(rety);

    }
        QSqlQueryModel* model = new QSqlQueryModel();
        QSqlQuery* qry1= new QSqlQuery(conn.mydb);

        {

        qry1->prepare("select * from pharmacy where Date='"+date+"'");

        qry1->exec();
        model->setQuery(*qry1);
        ui->tableView_2->setModel(model);
        }
    }
     conn.connClose();

    }


void Report::on_pushButton_3_clicked()
{
    QString disease,diseasex,idx,year;
    disease=ui->comboBox->currentText();
    qDebug() << disease;
    diseasex=disease+" positive";

    year=ui->comboBox_2->currentText();

    qDebug() << year;


    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from laboratory where Result='"+diseasex+"'");
    int countx = 0;

    if(qry.exec())
    {
        QString mon[12];
        int monx[12];
        while (qry.next())
        {
          idx=qry.value(5).toString();
          QRegExp tagExp("-");
          QStringList firstList = idx.split(tagExp);
          QString dte = firstList.at(1);
          QString dyr = firstList.at(2);
          if(dyr==year){
              int keyx = 0;
              qDebug() <<"--"<<dte;
              for(int k = 0; k < 12; k++){
                if(dte == mon[k]){
                  keyx=1;
                  monx[k] = monx[k]+1;
                  mon[k] = dte;

                }else{
                    if(k==11){
                        if(keyx==0){
                           mon[countx] = dte;
                           monx[countx] = 1;
                           countx++;

                        }
                    }
                }
              }
            }

        }

        // generate some data:
        QVector<double> ax(100), ay(100); // initialize with entries 0..100

        qDebug() <<"total--"<<countx;
        for(int k = 0; k < 12; k++){
          if(mon[k]!=""){
              ax[k+1] = mon[k].toInt();
              ay[k+1] = monx[k];
          }else{
              ax[k+1] = mon[k].toInt();
              ay[k+1] = 0;
          }
          qDebug() <<"=="<<ax[k];
          qDebug() <<"-"<<ay[k];
        }

        // create graph and assign data to it:


        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(ax, ay);
        QLinearGradient gradient(0,0,0,200);
        ui->customPlot->setBackground(QBrush(gradient));

        // give the axes some labels:
        ui->customPlot->xAxis->setLabel("Months of the year");
        ui->customPlot->yAxis->setLabel("Patient Visits");

        QVector<double> ticks;
        QVector<QString> labels;
        ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12;
        labels << "January" << "Febuary" << "March" << "April" << "May" << "June" << "July" << "August" << "September" << "October" <<"November" << "December";
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTicks(ticks, labels);
        ui->customPlot->xAxis->setTicker(textTicker);
        ui->customPlot->xAxis->setTickLabelRotation(60);
        ui->customPlot->xAxis->setSubTicks(false);
        ui->customPlot->xAxis->setTickLength(0, 4);
        ui->customPlot->xAxis->setRange(0, 13);
        ui->customPlot->xAxis->setBasePen(QPen(Qt::black));
        ui->customPlot->xAxis->setTickPen(QPen(Qt::black));
        ui->customPlot->xAxis->grid()->setVisible(true);
        ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
        ui->customPlot->xAxis->setTickLabelColor(Qt::black);
        ui->customPlot->xAxis->setLabelColor(Qt::black);


        ui->customPlot->yAxis->setRange(0, countx);
        ui->customPlot->replot();

        }

     }



