/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_push_button.cpp
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
#include <QBitmap>

#include "fm_push_button.h"

FMPushButton::FMPushButton(QString path, QString tipText, QWidget* parent) : QPushButton(parent)
{
    setToolTip(tipText);
    setFlat(true);
    setWindowOpacity(0);

    m_pixmap.load(path);
    m_iconWidth = m_pixmap.width() / 3;
    m_iconHeight = m_pixmap.height();

	setIconPos(0, 0, m_iconWidth, m_iconHeight);
    setIconSize(QSize(m_iconWidth, m_iconHeight));
}
void FMPushButton::enterEvent(QEvent*)
{
    setWindowOpacity(0.1);
	setIconPos(m_iconWidth, 0, m_iconWidth, m_iconHeight);
}
void FMPushButton::mousePressEvent(QMouseEvent*)
{
    setWindowOpacity(0.3);
	setIconPos(m_iconWidth * 2, 0, m_iconWidth, m_iconHeight);
}
void FMPushButton::mouseReleaseEvent(QMouseEvent*)
{
    setWindowOpacity(0.1);
	setIconPos(m_iconWidth, 0, m_iconWidth, m_iconHeight);
    emit clicked();
}
void FMPushButton::leaveEvent(QEvent*)
{
    setWindowOpacity(0);
	setIconPos(0, 0, m_iconWidth, m_iconHeight);
}

void FMPushButton::setIconPos(const qint32 x, const qint32 y, const qint32 width, const qint32 height)
{
	setIcon(QIcon(m_pixmap.copy(x, y, width, height)));
}
