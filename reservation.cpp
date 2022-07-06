#include "reservation.h"
#include "ui_reservation.h"
#include "split.h"

reservation::reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    ui->setupUi(this);
}

reservation::~reservation()
{
    delete ui;
}

void reservation::on_pushButton_clicked() //예약 조회
{
    ui->listWidget->clear();
    SQL="SELECT * FROM reservationTB";
    query.exec(QString::fromStdString(SQL));
    rec=query.record();
    ui->listWidget->addItem("[아이디]\t[여행지]\t[숙소명]\t[가이드]\t[예약일]");
    while(query.next())
    {
        ui->listWidget->addItem(
                    query.value(rec.indexOf("userId")).toString()+"\t"+
                    query.value(rec.indexOf("beach")).toString()+"\t"+
                    query.value(rec.indexOf("facility")).toString()+"\t"+
                    query.value(rec.indexOf("guideName")).toString()+"\t"+
                    query.value(rec.indexOf("date")).toString());
    }
}

void reservation::on_pushButton_2_clicked() //예약 삭제
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    vector<string> result = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(result[0]);
    if(result[0]!="[아이디]")
    {
        SQL="DELETE FROM reservationTB WHERE userId= '"+result[0]+"' and beach = '"+result[1]+"' and facility = '"+result[2]+"' and guideName = '"+result[3]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","예약 삭제가 완료되었습니다");
        on_pushButton_clicked();
    }
}

void reservation::on_pushButton_3_clicked() //예약일 수정
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    string updateText=ui->lineEdit->text().toStdString();
    vector<string> result = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(result[0]);
    if(result[0]!="[아이디]")
    {
        SQL="UPDATE reservationTB SET date = '"+updateText+"' WHERE userId= '"+result[0]+"' and beach = '"+result[1]+"' and facility = '"+result[2]+"' and guideName = '"+result[3]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","예약일이 수정되었습니다");
        on_pushButton_clicked();
    }
}
