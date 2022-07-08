#include "tourist.h"
#include "ui_tourist.h"
#include "menu.h"

tourist::tourist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tourist)
{
    ui->setupUi(this);
}

tourist::~tourist()
{
    delete ui;
}

void tourist::on_search_btn_clicked()
{
    ui->tableWidget->clear();
        SQL="SELECT * FROM beachTB";
        query.exec(QString::fromStdString(SQL));
        rec=query.record();
        int i=0;
        while(query.next())
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(rec.indexOf("local")).toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(rec.indexOf("office")).toString()));
            ui->tableWidget->setItem(i++,2,new QTableWidgetItem(query.value(rec.indexOf("beach")).toString()));
        }
}

void tourist::on_back_btn_clicked()
{
    this->hide();
    menu menu(Get_id);
    menu.setModal(true);
    menu.exec();
    this->show();
}
