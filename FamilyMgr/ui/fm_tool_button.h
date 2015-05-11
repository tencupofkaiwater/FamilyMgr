/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_tool_button.h
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
class QVBoxLayout;

class FMToolButton : public QWidget
{
    Q_OBJECT
public:
    explicit FMToolButton(QString path, QString text, QWidget* parent = 0);

	void setFocusBtn();
	void setNofocusBtn();
	QString getName();
    
signals:
    void toolBtnClicked(FMToolButton*);

public slots:

protected:
    void paintEvent(QPaintEvent*);
    void enterEvent(QEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void leaveEvent(QEvent *);

private:
	void setBkPalette(const quint32 p);

private:
    bool m_isFocus;
	QString m_name;
	QVBoxLayout* m_vboxLayout;
	QLabel* m_picLabel;
	QLabel* m_textLabel;
};
