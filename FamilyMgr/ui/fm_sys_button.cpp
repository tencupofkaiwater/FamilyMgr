/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_sys_button.cpp
* @version
* @brief
* @author   duye
* @date     2015-01-20
* @note
*
*  1. 2015-01-20 duye created this file
*
*/
#include <QPainter>
#include "fm_sys_button.h"

FMSysButton::FMSysButton(QString path, QString tipText, QWidget *parent) :
    QPushButton(parent)
{
    pixmap.load(path);
    setWindowOpacity(0);
    setFlat(true);
    btnWidth = pixmap.width() / 4;
    btnHeight = pixmap.height();
    setFixedSize(btnWidth,btnHeight);
    setToolTip(tipText);
    status = NORMAL;
}
void FMSysButton::enterEvent(QEvent *)
{
    status = ENTER;
    update();
}
void FMSysButton::mousePressEvent(QMouseEvent *)
{
    status = PRESS;
    update();
}
void FMSysButton::mouseReleaseEvent(QMouseEvent *)
{
    status = ENTER;
    update();
    emit clicked();
}
void FMSysButton::leaveEvent(QEvent *)
{
    status = NORMAL;
    update();
}

void FMSysButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), pixmap.copy(btnWidth * status, 0, btnWidth, btnHeight));
}
