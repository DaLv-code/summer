#include "facility.h"
#include "ui_facility.h"
#include "database.h"
#include "split.h"
using namespace std;

facility::facility(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::facility)
{
    ui->setupUi(this);
}

facility::~facility()
{
    delete ui;
}

void facility::on_pushButton_clicked() //숙소 조회
{
    ui->listWidget->clear();
    SQL="SELECT * FROM facilityTB";
    query.exec(QString::fromStdString(SQL));
    rec=query.record();
    ui->listWidget->addItem("[숙소명]\t\t\t[남은 객실수]");
    while(query.next())
    {
        ui->listWidget->addItem(query.value(rec.indexOf("facility")).toString()+"\t\t\t"+query.value(rec.indexOf("roomCount")).toString());
    }
}

void facility::on_pushButton_2_clicked() //숙소 이름 수정
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    string updateText=ui->lineEdit->text().toStdString();
    vector<string> result = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(result[0]);
    if(result[0]!="[숙소명]")
    {
        SQL="UPDATE facilityTB SET facility = '"+updateText+"' WHERE facility = '"+result[0]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","숙소 이름수정이 완료되었습니다");
        on_pushButton_clicked();
    }
}

void facility::on_pushButton_3_clicked() //숙박 인원 변경
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    string updateText=ui->lineEdit_2->text().toStdString();
    vector<string> result = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(result[0]);
    if(result[0]!="[숙소명]")
    {
        SQL="UPDATE facilityTB SET roomCount = '"+updateText+"' WHERE facility = '"+result[0]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","숙박 가능 인원이 변경되었습니다");
        on_pushButton_clicked();
    }
}

void facility::on_pushButton_4_clicked() //숙소 삭제
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    vector<string> result = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(result[0]);
    if(result[0]!="[숙소명]")
    {
        SQL="DELETE FROM facilityTB WHERE facility = '"+result[0]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","숙소 삭제가 완료되었습니다");
        on_pushButton_clicked();
    }
}
