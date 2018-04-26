#include "mainwindow/mainwindow.h"
#include "login/logindialog.h"
#include "global/globaldef.h"
#include <QApplication>
#include <stdio.h>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LOADQSS(GLOBALDEF::QSSPATH);

    CONFIGJSON->readConfig();

    QTranslator translater;
    if(CONFIGJSON->getLanguage().toInt())
    {
        if(translater.load(GLOBALDEF::ENGLISH))
        {
            a.installTranslator(&translater);
        }
        MAINWINDOW->translateLanguage();
    }

    {
        CONFIGINI->writeLanguage(CONFIGJSON->getLanguage());
        CONFIGINI->writeVersion(GLOBALDEF::VERSION);
    }

    LOGINDIALOG->show();

    if(LOGINDIALOG->exec() == QDialog::Accepted)
    {
        MAINWINDOW->checkUpdate();
        MAINWINDOW->showMaximized();
        if(NULL != argv) MAINWINDOW->setExeName(QString(argv[0]));
    }
    else
    {
        LOGINDIALOG->close();
        MAINWINDOW->close();
        qApp->exit();

        return 0;
    }

    return a.exec();
}
