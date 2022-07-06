#ifndef USER_H
#define USER_H

#include <QDialog>
#include "database.h"
using namespace std;

namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr);
    ~user();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::user *ui;
    QSqlQuery query;
    QSqlRecord rec;
    string SQL;
};

#endif // USER_H
