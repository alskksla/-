#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H
#include <QWidget>
#include <QStackedWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include<QGridLayout>
#include<QLayout>
#include<QHBoxLayout>
#include "mysqlwidget.h"

class MainWindow;

class ConfigWidget : public QWidget
{
    Q_OBJECT
public:

     explicit ConfigWidget(MainWindow *parent = nullptr);
signals:
    void sendlogion();
public slots:
    void on_btn0cClicked();
    void on_btn1cClicked();
    void on_btn2cClicked();
private:
    QWidget* createLoggionWidget();
    QWidget* createRegisterWidget();
private:
   MainWindow* m_parent;
   QPushButton m_btn[4];
   QLineEdit m_li[5];
   QLabel m_la[5];
   QStackedWidget * m_stactWidget;

private:
   MySQLWidget* m_mysql;
};

#endif // CONFIGWIDGET_H
