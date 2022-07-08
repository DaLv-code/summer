#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include "database.h"

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT

public:
    explicit reservation(QWidget *parent = nullptr);
    ~reservation();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::reservation *ui;
    QSqlQuery query;
    QSqlRecord rec;
    string SQL;
};

#endif // RESERVATION_H
