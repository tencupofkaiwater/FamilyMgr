/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_tool_widget.cpp
* @version
* @brief
* @author   duye
* @date     2015-01-20
* @note
*
*  1. 2015-01-20 duye created this file
*
*/
#include <QLabel>
#include <QHBoxLayout>

#include "fm_tool_widget.h"
#include "fm_tool_button.h"

FMToolWidget::FMToolWidget(QWidget* parent) : QWidget(parent), m_mainLayout(NULL)
{
    setFixedHeight(90);
}

void FMToolWidget::addToolBtnStart()
{
	m_mainLayout = new QHBoxLayout(this);
	m_mainLayout->setContentsMargins(5, 0, 5, 0);
}

void FMToolWidget::addToolBtn(QString picPath, QString name)
{
	FMToolButton* toolBtn = new FMToolButton(picPath, name, this);
	if (m_mainLayout->count() == 0)
	{
		toolBtn->setFocusBtn();
	}
	
	connect(toolBtn, SIGNAL(toolBtnClicked(FMToolButton*)), this, SLOT(toolBtnClicked(FMToolButton*)));
	m_mainLayout->addWidget(toolBtn);
	
	m_toolButtonList.push_back(toolBtn);
}

void FMToolWidget::addToolBtnEnd()
{
	m_mainLayout->addStretch();
	setLayout(m_mainLayout);
}

void FMToolWidget::toolBtnClicked(FMToolButton* focusToolBtn)
{
	foreach (auto toolBtn, m_toolButtonList)
	{
		toolBtn->setNofocusBtn();
	}

	focusToolBtn->setFocusBtn();

	emit contentChange(focusToolBtn->getName());
}
