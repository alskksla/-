//解决中文显示问题
#pragma execution_character_set("utf-8")

#include "workthread.h"
#include <QAxObject>
#include <QDebug>
#include <QTime>
#include <workthread.h>
#include <windows.h>

WorkThread::WorkThread(int i)
{
    odd = i;
}


void WorkThread::run()
{
    QTime t;
    QAxObject *pWordApplication = new QAxObject("Word.Application",0);
    QAxObject *pWordDocuments = pWordApplication->querySubObject("Documents");
    QString fileName = m_OpenPath;
    QString toFilePath = m_SavePath;

    QVariant filename(fileName);
    QVariant confirmconversions(false);
    QVariant readonly(true);
    QVariant addtorecentfiles(false);
    QVariant passworddocument("");
    QVariant passwordtemplate("");
    QVariant revert(false);

    QAxObject *doc = pWordDocuments->querySubObject("Open(const QVariant&, const QVariant&,const QVariant&, "
                                                    "const QVariant&, const QVariant&, "
                                                    "const QVariant&,const QVariant&)",
                                                    filename,
                                                    confirmconversions,
                                                    readonly,
                                                    addtorecentfiles,
                                                    passworddocument,
                                                    passwordtemplate,
                                                    revert);

    QVariant OutputFileName(toFilePath);
    QVariant ExportFormat(17);  //转换PDF
    QVariant OpenAfterExport(false);

    doc->querySubObject("ExportAsFixedFormat(const QVariant&,const QVariant&,const QVariant&)",
                        OutputFileName,
                        ExportFormat,
                        OpenAfterExport);
    doc->dynamicCall("Close(boolean)",false);
   OleUninitialize();//关闭


}
