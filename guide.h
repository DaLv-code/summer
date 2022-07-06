#ifndef GUIDE_H
#define GUIDE_H

#include <QDialog>
#include "database.h"
using namespace std;

namespace Ui {
class guide;
}

class guide : public QDialog
{
    Q_OBJECT

public:
    guide(QWidget *parent = nullptr);
    ~guide();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::guide *ui;
    QSqlQuery query;
    QSqlRecord rec;
    string SQL;
};

#endif // GUIDE_H
