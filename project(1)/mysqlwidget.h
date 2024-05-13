#ifndef MYSQLWIDGET_H
#define MYSQLWIDGET_H
#include <QSqlDatabase>     //连接数据库
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include<QString>


class MySQLWidget
{
public:
    MySQLWidget();
    ~MySQLWidget();
private:
    void Init();
    bool createUserTable();
    bool createLogTable();
public:
    bool registerUser(QString&username,QString&password);
    bool deleteUser(QString&username);
    bool loginUser(QString&username,QString&password);
    bool chanePasswd(const QString &username,  const QString &newpassword);
private:
    QSqlDatabase m_db;
};

#endif // MYSQLWIDGET_H
