#ifndef CONVERTWIDGET_H
#define CONVERTWIDGET_H
#include <QWidget>
#include<QGridLayout>
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include<QLayout>
#include<QHBoxLayout>
#include <QStackedWidget>
#include"workthread.h"
#include <QTextBrowser>
#include "mysqlwidget.h"

class MainWindow;
class ConvertWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConvertWidget(MainWindow *parent = nullptr);

public slots:
    void on_btnClicked();
    void on_OpenPath();
    void on_SavePath();
    void on_Start();
    void on_threadfinish();
    void addLogText(QString text,bool addtime = true);
    void on_exit();
    void on_clear();
    void on_deleteUser();
    void on_changpassword();

signals:
    void exit();
private:
    QWidget * createTopWidget();
    QWidget * createTButtomWidget();
    QWidget * setConfigWidget();

    QStackedWidget* m_staticWidget;
    QWidget * m_setWiget;
    QPushButton m_btn[3];
    QLineEdit m_li[4];
    QLabel  m_la[4];
    QString m_openFilePath;
    QString m_saveFilePath;
    QTextBrowser* m_LogText;
    int count;

private:
  MainWindow* m_parent;
private:
    WorkThread *workThread[7];

//private:
//   MySQLWidget* m_mysql;

};

#endif // CONVERTWIDGET_H
