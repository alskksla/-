#ifndef CONFIGWIDGET2_H
#define CONFIGWIDGET2_H

#include "mainwindow.h"
#include "mysqlwidget.h"
#include <QWidget>

namespace Ui {
class configwidget2;
}

class configwidget2 : public QWidget
{
    Q_OBJECT

public:
    explicit configwidget2(QWidget *parent = nullptr);
    ~configwidget2();

private slots:

    void on_loginButton_clicked();
    void on_regitButton_clicked();

    void on_tologin_clicked();

    void on_regit_clicked();

signals:
    void sendlogion();
private:
    MainWindow* m_parent;
private:
    MySQLWidget* m_mysql;
private:
    Ui::configwidget2 *ui;
};

#endif // CONFIGWIDGET2_H
