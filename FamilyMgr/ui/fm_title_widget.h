/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_title_widget.h
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

#include <QWidget>

class QLabel;
class FMPushButton;
class FMSysButton;

class FMTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FMTitleWidget(QString& title, QWidget* parent = 0);
    
signals:
	void doSkin();
	void doSetting();
    void doMin();
    void doMax();
	void doFullScreen();
	void doReturnSrcScreem();
	void doClose();
    
public slots:

protected:
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);

private:
    QPoint m_pressedPoint;
    bool m_isMove;

	QLabel* m_titleLabel;
    FMPushButton* m_btnSkin;
    FMSysButton* m_btnSetting;
    FMSysButton* m_btnMin;
    FMSysButton* m_btnMax;
    FMSysButton* m_btnClose;
};
