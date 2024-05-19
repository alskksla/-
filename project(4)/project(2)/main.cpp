
#include<QWidget>
#include <QApplication>
#include <QSqlDatabase>     //连接数据库
#include <QDebug>
#include <QSqlError>
#include "mainwindow.h"
#include <QSqlQuery>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


