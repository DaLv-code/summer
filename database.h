#ifndef DB_H
#define DB_H

#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <cstring>
using namespace std;

class DB
{
protected:
    QSqlDatabase db;

public:
    DB() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("tourist");
        db.setHostName("10.10.20.35");
        db.setUserName("open");
        db.setPassword("root1234");
        db.setPort(3306);
        if (db.open()&&db.isOpen()){
            QMessageBox::information(nullptr,"Succsefull","Connect To Mysql");
        }
        else{
            QMessageBox::critical(nullptr,"Error",db.lastError().text());
        }
    }
    ~DB() {
        db.close();
    }
};

#endif
