#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_userButton_clicked();
    void on_touristButton_clicked();
    void on_facilityButton_clicked();
    void on_guideButton_clicked();

    void on_reservationButton_clicked();

private:
    Ui::MainWindow *ui;
    DB db;
};
#endif // MAINWINDOW_H
