#ifndef TOURIST_H
#define TOURIST_H

#include <QDialog>
#include "database.h"
using namespace std;

namespace Ui {
class tourist;
}

class tourist : public QDialog
{
    Q_OBJECT

public:
    explicit tourist(QWidget *parent = nullptr);
    ~tourist();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::tourist *ui;  
    QSqlQuery query;
    QSqlRecord rec;
    string SQL;
};

#endif // TOURIST_H
