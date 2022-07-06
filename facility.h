#ifndef FACILITY_H
#define FACILITY_H

#include <QDialog>
#include "database.h"
#include "ui_facility.h"
using namespace std;

namespace Ui {
class facility;
}

class facility : public QDialog
{
    Q_OBJECT

public:
    explicit facility(QWidget *parent = nullptr);
    ~facility();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::facility *ui;  
    QSqlQuery query;
    QSqlRecord rec;
    string SQL;
    QListWidgetItem *item;
};

#endif // FACILITY_H
