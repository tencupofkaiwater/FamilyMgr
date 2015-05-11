/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_account_widget.h
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

#include "ui/fm_content_widget.h"
#include "ui_fm_account.h"

class FMAccountWidget : public FMContentWidget
{
	Q_OBJECT

public:
	explicit FMAccountWidget(QWidget* parent = 0);

signals:
	public slots:

private:
	Ui::FMAccountWidget m_ui;
};