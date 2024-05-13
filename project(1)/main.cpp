
//#include "widget.h"
#include<QWidget>
#include <QApplication>
#include <QSqlDatabase>     //连接数据库
#include <QDebug>
#include <QSqlError>
#include "mainwindow.h"
#include <QSqlQuery>

// 注册函数
bool registerUser(const QString &username, const QString &password) {

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("localhost_3306");
    db.setUserName("root");
    db.setPassword("123456");

    if (!db.open()) {
        qDebug() << "数据库连接失败：" << db.lastError();
        return false;
    }



    //插入数据
         QSqlQuery query(db);
         QString qs = QString("insert into user1(username,password) values('%1','%2')").arg(username).arg(password);
         if(query.exec(qs)){     //如果插入数据成功
           qDebug()<<"注册成功";

         }else{
             //QMessageBox::information(this,"注册","注册失败");
              qDebug() << "注册失败：" << query.lastError();
             qDebug() <<query.lastError().text(); //输出错误信息
             return false;
         }

    return true; // 注册成功
}


bool loginUser(const QString &username, const QString &password) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("localhost_3306");
    db.setUserName("root");
    db.setPassword("123456");

    if (!db.open()) {
        qDebug() << "Database error occurred";
        return false;
    }


//
    QSqlQuery query(db);
    query.prepare("SELECT * FROM user1 WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Login failed: " << query.lastError();
        db.close();
        return false;
    }

    if (query.next()) {
        qDebug() << "Login successful";
             db.close();
        return true;
    } else {
         db.close();
        qDebug() << "Login failed: Invalid username or password";
        return false;
    }

     db.close();

}


void deletuser(const QString &username)
{

    // 建立数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("localhost_3306");
    db.setUserName("root");
    db.setPassword("123456");

    bool ok = db.open();
    if (ok) {

        QString query = QString("%1%2%3%4%5%6").arg("DROP USER ").arg("'").arg(username).arg("'").arg("@").arg("'localhost'");

            // 执行SQL语句
            QSqlQuery sqlQuery(db);


            QString sql = QString("delete from user1 where username = '%1'").arg(username);
            sqlQuery.exec(sql);


            if (sqlQuery.exec(sql)) {
                qDebug() << "User deleted successfully";
            } else {
                qDebug() << "Error deleting user:" << sqlQuery.lastError().text();
            }

        db.close();
    } else {
        qDebug() << "Error connecting to the database:" << db.lastError();
    }
}


void createUserTable() {
    // 连接到MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost"); // 数据库服务器地址
    db.setDatabaseName("localhost_3306"); // 数据库名
    db.setUserName("root"); // 数据库用户名
    db.setPassword("123456"); // 数据库密码

    bool ok = db.open();
    if (ok) {
        // 创建user表的SQL语句
        QString query = "CREATE TABLE IF NOT EXISTS user1 ("
                        "username VARCHAR(50) NOT NULL,"
                        "password VARCHAR(50) NOT NULL,"
                        "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
                        ")";

        QSqlQuery sqlQuery(db);
        if (!sqlQuery.exec(query)) {
            qDebug() << "Error creating user table:" << sqlQuery.lastError();
        } else {
            qDebug() << "User table created successfully";
        }
    } else {
        qDebug() << "Error connecting to the database:" << db.lastError();
    }

    db.close();
}


int chanepasswd(const QString &username,  const QString &newpassword,const QString &oldpassword)

{
    //查询密码是否正确,正确才给修改
    if(!loginUser(username,oldpassword))
    {
        qDebug()<<"密码不对";
        return  false;
    }

    // 初始化Qt的SQL数据库系统
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost"); // 数据库服务器地址
    db.setDatabaseName("localhost_3306"); // 数据库名
    db.setUserName("root"); // 数据库用户名
    db.setPassword("123456"); // 数据库密码

      // 打开数据库连接
      if (!db.open()) {
          qDebug() << "数据库连接失败：" << db.lastError();
          return -1;
      }

      // 创建SQL查询对象
      QSqlQuery query(db);


      {
          QString caozuo =QString("update user1 set password = '%1'where username = '%2'").arg(newpassword).arg(username);
//          if(qq.exec(caozuo))
      // 执行修改密码的SQL语句
     // bool success = query.exec("ALTER USER 'u1'@'localhost' IDENTIFIED BY '111';");
     bool success = query.exec(caozuo);
      if (!success) {
          qDebug() << "密码修改失败：" << query.lastError();
          return -2;
      }

        }
      qDebug() << "密码修改成功";

      // 关闭数据库连接
      db.close();
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

   // createUserTable();
    //注册
//      deletuser("u1");
//      registerUser("u1","123");
//      chanepasswd("u1","123","123");
//      loginUser("2","2");



    MainWindow w;
    w.show();
    return a.exec();
}



//#include "mainwindow.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}
