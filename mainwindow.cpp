#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "tourist.h"
#include "facility.h"
#include "guide.h"
#include "reservation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_userButton_clicked()
{
    this->close();
    user userWindow;
    userWindow.setModal(true);
    userWindow.exec();
    userWindow.setGeometry(0,0,681,342);
    this->show();
}

void MainWindow::on_touristButton_clicked()
{
    this->close();
    tourist touristWindow;
    touristWindow.setModal(true);
    touristWindow.exec();
    touristWindow.setGeometry(0,0,681,342);
    this->show();
}

void MainWindow::on_facilityButton_clicked()
{
    this->close();
    facility facilityWindow;
    facilityWindow.setModal(true);
    facilityWindow.exec();
    facilityWindow.setGeometry(0,0,681,342);
    this->show();
}

void MainWindow::on_guideButton_clicked()
{
    this->close();
    guide guideWindow;
    guideWindow.setModal(true);
    guideWindow.exec();
    guideWindow.setGeometry(0,0,681,342);
    this->show();
}

void MainWindow::on_reservationButton_clicked()
{
    this->close();
    reservation reservWindow;
    reservWindow.setModal(true);
    reservWindow.exec();
    reservWindow.setGeometry(0,0,681,342);
    this->show();
}
