#include "tourist.h"
#include "ui_tourist.h"
#include <QtDebug>
#include <QMessageBox>
#include <iostream>

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

void tourist::on_pushButton_clicked() //관광지 조회
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

void tourist::on_pushButton_2_clicked() //관광지 수정
{
    string updateText=ui->lineEdit->text().toStdString();
    QTableWidgetItem *currentText=ui->tableWidget->currentItem();
    int colNum=ui->tableWidget->currentColumn();
    int rowNum=ui->tableWidget->currentRow();
    qDebug()<<colNum;
    if(colNum==0)
        SQL="UPDATE beachTB SET local = '"+updateText+"' WHERE beach = '"+ui->tableWidget->item(rowNum, 2)->text().toStdString()+"'";
    else if(colNum==1)
        SQL="UPDATE beachTB SET office = '"+updateText+"' WHERE beach = '"+ui->tableWidget->item(rowNum, 2)->text().toStdString()+"'";
    else if(colNum==2)
        SQL="UPDATE beachTB SET beach = '"+updateText+"' WHERE beach = '"+currentText->text().toStdString()+"'";
    query.exec(QString::fromStdString(SQL));
    QMessageBox::information(nullptr,"Succsefull","관광지 수정이 완료되었습니다");
    on_pushButton_clicked();
}

void tourist::on_pushButton_3_clicked() //관광지 삭제
{
    QTableWidgetItem *currentText=ui->tableWidget->currentItem();
    int colNum=ui->tableWidget->currentColumn();
    qDebug()<<colNum;
    if(colNum==0)
        QMessageBox::information(nullptr,"Error","삭제할 관광지를 선택해주세요");
    else if(colNum==1)
        QMessageBox::information(nullptr,"Error","삭제할 관광지를 선택해주세요");
    else if(colNum==2)
    {
        SQL="DELETE FROM beachTB WHERE beach = '"+currentText->text().toStdString()+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","관광지 삭제가 완료되었습니다");
        on_pushButton_clicked();
    }
}
