/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_tool_button.cpp
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
#include <QVBoxLayout>
#include <QPalette>
#include <QPainter>
#include <QBitmap>

#include "fm_tool_button.h"

FMToolButton::FMToolButton(QString path, QString text, QWidget* parent) : QWidget(parent), m_isFocus(false)
{
	m_name = text;

    m_picLabel = new QLabel(this);

	QPixmap pixmap(path);
    m_picLabel->setPixmap(pixmap);
    m_picLabel->setFixedSize(pixmap.size());

    m_vboxLayout = new QVBoxLayout(this);
    m_vboxLayout->addWidget(m_picLabel, 0, Qt::AlignHCenter);

	m_textLabel = new QLabel(text, this);
    m_vboxLayout->addWidget(m_textLabel, 0, Qt::AlignHCenter);

    setLayout(m_vboxLayout);

    setBkPalette(0);
    setAutoFillBackground(true);
    setFixedHeight(80);
}

void FMToolButton::setFocusBtn()
{
	m_isFocus = true;
	setBkPalette(70);
}

void FMToolButton::setNofocusBtn()
{
	m_isFocus = false;
	setBkPalette(0);
}

QString FMToolButton::getName()
{
	return m_name;
}

void FMToolButton::enterEvent(QEvent*)
{
	if (!m_isFocus)
	{
		setBkPalette(30);
	}
}

void FMToolButton::mousePressEvent(QMouseEvent*)
{
	setBkPalette(70);
	emit toolBtnClicked(this);
}

void FMToolButton::mouseReleaseEvent(QMouseEvent*)
{
}

void FMToolButton::leaveEvent(QEvent*)
{
	if (!m_isFocus)
	{
		setBkPalette(0);
	}
}

void FMToolButton::paintEvent(QPaintEvent*)
{
    QBitmap bitmap(this->size());
    bitmap.fill();
    QPainter painter(&bitmap);
    painter.setRenderHints(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::black));
    painter.drawRoundedRect(bitmap.rect(), 5, 5);
    setMask(bitmap);
}

void FMToolButton::setBkPalette(const quint32 p)
{
	QPalette palette;
	palette.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255, p)));
	setPalette(palette);
}