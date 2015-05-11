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

FMSysButton::FMSysButton(QString path, QString tipText, QWidget* parent) : QPushButton(parent)
{
    m_pixmap.load(path);
    setWindowOpacity(0);
    setFlat(true);
    m_btnWidth = m_pixmap.width() / 4;
    m_btnHeight = m_pixmap.height();
    setFixedSize(m_btnWidth, m_btnHeight);
    setToolTip(tipText);
    m_status = NORMAL;
}
void FMSysButton::enterEvent(QEvent*)
{
    m_status = ENTER;
    update();
}
void FMSysButton::mousePressEvent(QMouseEvent*)
{
    m_status = PRESS;
    update();
}
void FMSysButton::mouseReleaseEvent(QMouseEvent*)
{
    m_status = ENTER;
    update();
    emit clicked();
}
void FMSysButton::leaveEvent(QEvent*)
{
    m_status = NORMAL;
    update();
}

void FMSysButton::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_pixmap.copy(m_btnWidth * m_status, 0, m_btnWidth, m_btnHeight));
}
