/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_skin_widget.cpp
* @version
* @brief
* @author   duye
* @date     2015-01-20
* @note
*
*  1. 2015-01-20 duye created this file
*
*/
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>

#include "fm_skin_widget.h"

FMSkinWidget::FMSkinWidget(QString picName, QWidget* parent) : m_bkPicName(picName), QWidget(parent)
{
	m_column = 4;

	m_signalMapper = new QSignalMapper(this);
	connect(m_signalMapper, SIGNAL(mapped(QString)), this, SIGNAL(changeSkin(QString)));
	connect(m_signalMapper, SIGNAL(mapped(QString)), this, SLOT(setSkin(QString)));

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel(QStringLiteral("¸ü»»Æ¤·ô")), 0, Qt::AlignHCenter);

	m_gridLayout = new QGridLayout(this);
    mainLayout->addLayout(m_gridLayout);
    setLayout(mainLayout);

    setWindowFlags(Qt::Popup);
}

void FMSkinWidget::addSkin(QString name, QString picPath)
{
	m_skinList.push_back(SkinPair(name, picPath));

	QPushButton* btn = new QPushButton(this);
	QIcon icon(picPath.left(picPath.indexOf(".")) + "_small.jpg");
	btn->setIcon(icon);
	btn->setIconSize(QSize(97, 62));
	btn->setToolTip(name);

	connect(btn, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
	m_signalMapper->setMapping(btn, picPath);

	m_gridLayout->addWidget(btn, (m_skinList.size() - 1) / m_column, (m_skinList.size() - 1) % m_column);
	m_gridLayout->setSpacing(0);
}

void FMSkinWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QPixmap(m_bkPicName)));
    painter.setRenderHints(QPainter::Antialiasing, true);
    painter.setPen(Qt::black);
    painter.drawRect(rect());
}

void FMSkinWidget::setSkin(QString picName)
{
    m_bkPicName = picName;
    update();
}
