#ifndef CONVERTWIDGET2_H
#define CONVERTWIDGET2_H

#include "qtextbrowser.h"
#include "workthread.h"
#include <QWidget>

namespace Ui {
class convertwidget2;
}

class convertwidget2 : public QWidget
{
    Q_OBJECT

public:
    explicit convertwidget2(QWidget *parent = nullptr);
    ~convertwidget2();
public slots:
    void on_btnClicked();
    void on_OpenPath();
    void on_SavePath();
    void on_Start();
    void on_threadfinish();
    void addLogText(QString text,bool addtime = true);
    void on_exit();
    void on_clear();
private slots:
    void on_deleteUser_clicked();
    void on_changePassward_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    int count;
    QString m_openFilePath;
    QString m_saveFilePath;
    QTextBrowser* m_LogText;
signals:
    void exit();
private:
     WorkThread *workThread[7];
private:
    Ui::convertwidget2 *ui;
};

#endif // CONVERTWIDGET2_H
