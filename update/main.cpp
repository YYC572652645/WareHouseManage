#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include "qreadwrite/qreadwriteini.h"
#include "globaldef.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translater;
    if(CONFIGINI->getLanguage().toInt())
    {
        if(translater.load(GLOBALDEF::ENGLISH))
        {
            a.installTranslator(&translater);
        }
    }

    MainWindow w;

    if(NULL != argv) w.setExeName(QString(argv[0]));

    w.show();

    return a.exec();
}

