#include "user.h"
#include "ui_user.h"
#include "split.h"
#include <QtDebug>
#include <QMessageBox>
#include <iostream>

user::user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_clicked() //회원 조회
{
    ui->listWidget->clear();
    SQL="SELECT userId, userName, userRating FROM userTB";
    query.exec(QString::fromStdString(SQL));
    rec=query.record();
    ui->listWidget->addItem("[유저 아이디]\t[유저 이름]\t\t[유저 등급]");
    while(query.next())
    {
        ui->listWidget->addItem(query.value(rec.indexOf("userId")).toString()
                                +"\t\t"+query.value(rec.indexOf("userName")).toString()
                                +"\t\t"+query.value(rec.indexOf("userRating")).toString());
    }
}

void user::on_pushButton_2_clicked() //회원 탈퇴
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    vector<string> result = split(item->text().toStdString(), '\t');
    if(result[0]!="[유저 아이디]")
    {
        SQL="INSERT INTO deluserTB VALUES('"+result[0]+"','"+result[2]+"')";
        query.exec(QString::fromStdString(SQL));

        SQL="DELETE FROM userTB WHERE userId='"+result[0]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","회원 탈퇴 처리가 완료되었습니다");
        on_pushButton_clicked();
    }
}

void user::on_pushButton_3_clicked() //탈퇴회원 조회
{
    ui->listWidget->clear();
    SQL="SELECT userId, userName FROM deluserTB";
    query.exec(QString::fromStdString(SQL));
    rec=query.record();
    ui->listWidget->addItem("[탈퇴한 아이디]\t[유저 이름]");
    while(query.next())
    {
        ui->listWidget->addItem(query.value(rec.indexOf("userId")).toString()+"\t\t"
                                +query.value(rec.indexOf("userName")).toString());
    }
}

void user::on_pushButton_4_clicked() //회원수정
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    string updateText=ui->lineEdit->text().toStdString();
    vector<string> result = split(item->text().toStdString(), '\t');
    if(result[0]!="[유저 아이디]")
    {
        SQL="UPDATE userTB SET userName = '"+updateText+"' WHERE userId = '"+result[0]+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(nullptr,"Succsefull","회원 이름수정이 완료되었습니다");
        on_pushButton_clicked();
    }
}
