/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_main.h
* @version
* @brief
* @author   duye
* @date     2015-01-20
* @note
*
*  1. 2015-01-20 duye created this file
*
*/

#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <QIcon>

#include "business/fm_main_widget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
	QApplication::setApplicationDisplayName(QStringLiteral("Íõ¹Ü¼Ò"));
	QApplication::setWindowIcon(QIcon("Resources/img/sys_logo.ico"));

    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);
    app.setPalette(palette);

    MainWidget win;
    win.show();
    
    return app.exec();
}
