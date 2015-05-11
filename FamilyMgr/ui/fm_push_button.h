/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_push_button.h
* @version
* @brief
* @author   duye
* @date     2015-01-20
* @note
*
*  1. 2015-01-20 duye created this file
*
*/
#pragma once

#include <QPushButton>

/**
 * @brief FMPushButton
 */
class FMPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit FMPushButton(QString path, QString tipText, QWidget* parent = 0);
    
signals:

protected:
    void enterEvent(QEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void leaveEvent(QEvent*);

private:
	void setIconPos(const qint32 x, const qint32 y, const qint32 width, const qint32 height);

private:
	QPixmap m_pixmap;
	int m_iconWidth;
	int m_iconHeight;
};
