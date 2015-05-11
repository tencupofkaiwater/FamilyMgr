/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_sys_button.h
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

class FMSysButton : public QPushButton
{
    Q_OBJECT
public:
    explicit FMSysButton(QString path, QString tipText, QWidget *parent = 0);
    
signals:
    
public slots:
    
private:
    enum buttonStatus{NORMAL, ENTER, PRESS, NOSTATUS};
    buttonStatus status;

	QPixmap pixmap;
    int btnWidth;
    int btnHeight;

protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void leaveEvent(QEvent *);
};
