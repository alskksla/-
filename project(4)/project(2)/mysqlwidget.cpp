#include "mysqlwidget.h"
#include<QMessageBox>
MySQLWidget::MySQLWidget()
{
Init();
}

MySQLWidget::~MySQLWidget()
{
//m_db.close();
}

void MySQLWidget::Init()
{
    createUserTable();
}

bool MySQLWidget::registerUser(QString&username,QString&password)
{
    // 连接到MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost"); // 数据库服务器地址
    db.setDatabaseName("localhost_3306"); // 数据库名
    db.setUserName("root"); // 数据库用户名
    db.setPassword("123456"); // 数据库密码

    if (!db.open()) {
        qDebug() << "数据库连接失败：" << m_db.lastError();
        db.close();
        return false;
    }

        qDebug()<<"username"<<username<<"password"<<password;
    //插入数据
         QSqlQuery query;
        QString qs = QString("insert into user1(username,password) values('%1','%2')").arg(username).arg(password);


         if(query.exec(qs))
         {
               qDebug()<<"注册成功";

               db.close();
               return  true;
         }else{
             //   QMessageBox::information(this,"注册","注册失败");
                qDebug() << "注册失败：" << query.lastError();
                 db.close();
                return false;
         }


}



bool MySQLWidget::deleteUser(QString&username)
{
    // 连接到MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost"); // 数据库服务器地址
    db.setDatabaseName("localhost_3306"); // 数据库名
    db.setUserName("root"); // 数据库用户名
    db.setPassword("123456"); // 数据库密码

    bool ok = db.open();
    if (ok) {
                // 执行SQL语句
                QSqlQuery sqlQuery(db);
                QString sql = QString("delete from user1 where username = '%1'").arg(username);
                sqlQuery.exec(sql);


            if (sqlQuery.exec(sql))
                {
                        qDebug() << "User deleted successfully";
                        return  true;
                } else {

                qDebug() << "Error deleting user:" << sqlQuery.lastError().text();
                return  false;
                }

        } else {
            qDebug() << "Error connecting to the database:" << m_db.lastError();
        }

}
bool MySQLWidget::loginUser(QString&username,QString&password)
{
    // 连接到MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost"); // 数据库服务器地址
    db.setDatabaseName("localhost_3306"); // 数据库名
    db.setUserName("root"); // 数据库用户名
    db.setPassword("123456"); // 数据库密码


    if (!db.open())
    {
        qDebug() << "Database error occurred";
    }



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
        qDebug() << "Login failed: Invalid username or password";
        db.close();
        return false;
    }
}
bool MySQLWidget::chanePasswd(const QString &username,  const QString &newpassword)
{


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

bool MySQLWidget::createUserTable()
{
    qDebug()<<"createUserTable";
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
            if (!sqlQuery.exec(query))
            {
                qDebug() << "Error creating user table:" << sqlQuery.lastError();
                return false;
            } else {
                qDebug() << "User table created successfully";
                return  true;

            }
            } else {

                qDebug() << "Error connecting to the database:" << db.lastError();
                return false;
            }

}
bool MySQLWidget::createLogTable()
{
    bool ok = m_db.open();
    if (ok) {
        // 创建user表的SQL语句
        QString query = "CREATE TABLE IF NOT EXISTS user1 ("
                        "log VARCHAR(50) NOT NULL,"
                        "text VARCHAR(50) NOT NULL,"
                        "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
                        ")";

            QSqlQuery sqlQuery(m_db);
            if (!sqlQuery.exec(query))
            {
                qDebug() << "Error creating user table:" << sqlQuery.lastError();
                return false;
            } else {
                qDebug() << "User table created successfully";
                return  true;

            }
            } else {

                qDebug() << "Error connecting to the database:" << m_db.lastError();
                return false;
            }
}
