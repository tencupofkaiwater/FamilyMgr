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

FMStatusWidget::FMStatusWidget(QWidget *parent) :
    QWidget(parent)
{
    QLabel* labelVersion = new QLabel(QStringLiteral("主程序版本:1.0.0.1"), this);
    QLabel* labelHorse = new QLabel(QStringLiteral("更新时间:2015-01-26"), this);
    QLabel* labelUpdate = new QLabel(QStringLiteral("检查更新"), this);
    QLabel* labelConn360 = new QLabel(QStringLiteral("未连接至VP中心"), this);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->addWidget(labelVersion);
    labelVersion->setContentsMargins(5,0,0,0);
    mainLayout->addWidget(labelHorse);
    mainLayout->addWidget(labelUpdate);
    mainLayout->addStretch();
    mainLayout->addWidget(labelConn360);
    labelConn360->setContentsMargins(0,0,40,0);
    setLayout(mainLayout);

    setFixedHeight(25);
}
