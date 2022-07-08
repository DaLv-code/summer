#include "user_infor.h"
#include "ui_user_infor.h"
#include "signup.h"
#include "menu.h"
#include "login.h"

user_infor::user_infor(std::string Get_id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_infor)
{
    ui->setupUi(this);
    this->Get_id = Get_id;
}

user_infor::~user_infor()
{
    delete ui;
}

void user_infor::on_change_name_btn_clicked()
{
    std::string Get_name=ui->change_name->text().toStdString();
    SQL = "UPDATE userTB SET userName = '"+ui->change_name->text().toStdString()+"'WHERE userId = '"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    QMessageBox::information(this,"저기어때","이름이 변경되었습니다.");
}

void user_infor::on_change_pw_btn_clicked()
{
    std::string Get_pw=ui->change_pw->text().toStdString();
    SQL = "UPDATE userTB SET userPw = '"+ui->change_pw->text().toStdString()+"'WHERE userId = '"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    QMessageBox::information(this,"저기어때","비밀번호가 변경되었습니다.");
}

void user_infor::on_withdraw_btn_clicked()
{
    SQL = "DELETE FROM userTB WHERE userId = '"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    QMessageBox::warning(this,"저기어때","잘가~");
    this->close();
}

void user_infor::on_back_btn_clicked()
{
    this->hide();
    menu menu(Get_id);
    menu.setModal(true);
    menu.exec();
    this->show();
}
