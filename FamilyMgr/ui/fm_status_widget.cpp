/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_status_widget.cpp
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

#include "fm_status_widget.h"

FMStatusWidget::FMStatusWidget(QWidget* parent) : QWidget(parent)
{
    QLabel* labelOldVersion = new QLabel(QStringLiteral("当前版本:1.0.0.1"), this);
    QLabel* labelTime = new QLabel(QStringLiteral("更新时间:2015-01-26"), this);
	QLabel* labelNewVersion = new QLabel(QStringLiteral("最新版本:1.0.0.1"), this);
    QLabel* labelUpdate = new QLabel(QStringLiteral("更新"), this);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->addWidget(labelOldVersion);
    labelOldVersion->setContentsMargins(5, 0, 0, 0);
    mainLayout->addWidget(labelTime);

	mainLayout->addStretch();
	mainLayout->addWidget(labelNewVersion);
	labelNewVersion->setContentsMargins(5, 0, 0, 0);
    mainLayout->addWidget(labelUpdate);
	labelUpdate->setContentsMargins(0, 0, 5, 0);
    
    setLayout(mainLayout);

    setFixedHeight(30);
}
