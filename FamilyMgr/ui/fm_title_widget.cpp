/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_title_widget.cpp
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

#include <QLabel>
#include <QHBoxLayout>
#include <QApplication>
#include <QMessageBox>
#include <QMouseEvent>

#include "fm_title_widget.h"
#include "fm_sys_button.h"
#include "fm_push_button.h"

FMTitleWidget::FMTitleWidget(QString& title, QWidget* parent) : QWidget(parent)
{
	m_titleLabel = new QLabel(title, this);

    m_btnSkin = new FMPushButton("Resources/img/sys_skin.png", QStringLiteral("换肤"), this);
    connect(m_btnSkin, SIGNAL(clicked()), this, SIGNAL(doSkin()));

    m_btnSetting = new FMSysButton("Resources/img/sys_setting.png", QStringLiteral("设置"), this);
	connect(m_btnSetting, SIGNAL(clicked()), this, SIGNAL(doSetting()));

    m_btnMin = new FMSysButton("Resources/img/sys_min.png", QStringLiteral("最小化"), this);
    connect(m_btnMin, SIGNAL(clicked()), this, SIGNAL(doMin()));

    m_btnMax = new FMSysButton("Resources/img/sys_max.png", QStringLiteral("最大化"), this);
    connect(m_btnMax, SIGNAL(clicked()), this, SIGNAL(doMax()));

    m_btnClose = new FMSysButton("Resources/img/sys_close.png", QStringLiteral("关闭"), this);
    connect(m_btnClose, SIGNAL(clicked()), this, SIGNAL(doClose()));

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_titleLabel, 0, Qt::AlignVCenter);
    m_titleLabel->setContentsMargins(5, 0, 0, 0);
    mainLayout->addStretch();
    mainLayout->addWidget(m_btnSkin, 0, Qt::AlignVCenter);
    m_btnSkin->setContentsMargins(0, 0, 5, 0);
    mainLayout->addWidget(m_btnSetting);
    mainLayout->addWidget(m_btnMin);
    mainLayout->addWidget(m_btnMax);
    mainLayout->addWidget(m_btnClose);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);
    setFixedHeight(25);
    m_isMove = false;
}

void FMTitleWidget::mousePressEvent(QMouseEvent* e)
{
    if (e->x() + 170 >= this->width())
	{
        return;
	}

    m_pressedPoint = e->pos();
    m_isMove = true;
}

void FMTitleWidget::mouseMoveEvent(QMouseEvent* e)
{
    if ((e->buttons() & Qt::LeftButton) && m_isMove)
    {
        static QWidget* parWidget = this->parentWidget();
        QPoint nowParPoint = parWidget->pos();
        nowParPoint.setX(nowParPoint.x() + e->x() - m_pressedPoint.x());
        nowParPoint.setY(nowParPoint.y() + e->y() - m_pressedPoint.y());
        parWidget->move(nowParPoint);
    }
}

void FMTitleWidget::mouseReleaseEvent(QMouseEvent*)
{
    if (m_isMove)
	{
        m_isMove = false;
	}
}

void FMTitleWidget::mouseDoubleClickEvent(QMouseEvent* e)
{
    if (e->x() + 170 >= this->width())
	{
        return;
	}

	static bool isFull = false;

	if (isFull)
	{
		emit doReturnSrcScreem();
		isFull = false;
	}
	else
	{
		emit doFullScreen();
		isFull = true;
	}
}
