#include "guide.h"
#include "ui_guide.h"
#include "split.h"


guide::guide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guide)
{
    ui->setupUi(this);
}

guide::~guide()
{
    delete ui;
}

void guide::on_pushButton_clicked() //가이드 조회
{
    ui->listWidget->clear();
    SQL="SELECT * FROM guideTB";
    query.exec(QString::fromStdString(SQL));
    rec=query.record();
    ui->listWidget->addItem("[가이드 이름]\t[가이드 상태]");
    while(query.next())
    {
        ui->listWidget->addItem(query.value(rec.indexOf("guideName")).toString()+"\t\t"+query.value(rec.indexOf("guideOK")).toString());
    }
}

void guide::on_pushButton_2_clicked() //가이드 추가
{
    string updateText=ui->lineEdit->text().toStdString();
    SQL="INSERT INTO guideTB(guideName) VALUES('"+updateText+"')";
    query.exec(QString::fromStdString(SQL));
    QMessageBox::information(nullptr,"Succsefull","가이드가 추가되었습니다");
    on_pushButton_clicked();
}


void guide::on_pushButton_3_clicked() //가이드 수정
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    string updateText=ui->lineEdit_2->text().toStdString();
    vector<string> result = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(result[0]);
    if(result[0]!="[가이드 이름]")
    {
        SQL="UPDATE guideTB SET guideName = '"+updateText+"' WHERE guideName = '"+result[0]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","가이드 이름수정이 완료되었습니다");
        on_pushButton_clicked();
    }
}

void guide::on_pushButton_4_clicked() //가이드 삭제
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    vector<string> result = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(result[0]);
    if(result[0]!="[가이드 이름]")
    {
        SQL="DELETE FROM guideTB WHERE guideName = '"+result[0]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","가이드 삭제가 완료되었습니다");
        on_pushButton_clicked();
    }
}

void guide::on_pushButton_5_clicked() //가이드 상태변경
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    vector<string> result = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(result[0]);
    if(result[0]!="[가이드 이름]")
    {
        SQL="UPDATE guideTB SET guideOK = '1' WHERE guideName = '"+result[0]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","가이드 상태변경이 완료되었습니다");
        on_pushButton_clicked();
    }
}
