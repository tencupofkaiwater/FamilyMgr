/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_tool_widget.h
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
#include <QList>

class QHBoxLayout;
class FMToolButton;

typedef QList<FMToolButton*> FMToolButtonList;

class FMToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FMToolWidget(QWidget* parent = 0);

	void addToolBtnStart();
	void addToolBtn(QString picPath, QString name);
	void addToolBtnEnd();
    
signals:
    void contentChange(QString);

public slots:
	void toolBtnClicked(FMToolButton*);
    
private:
	QHBoxLayout* m_mainLayout;
	FMToolButtonList m_toolButtonList;
};
