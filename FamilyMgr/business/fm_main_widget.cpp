/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_main_widget.cpp
* @version
* @brief
* @author   duye
* @date     2015-01-20
* @note
*
*  1. 2015-01-20 duye created this file
*
*/
#include <QBitmap>
#include <QPainter>
#include <QBrush>
#include <QVBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QStackedLayout>

#include "ui/fm_title_widget.h"
#include "ui/fm_tool_widget.h"
#include "ui/fm_status_widget.h"
#include "ui/fm_skin_widget.h"

#include "fm_account_widget.h"
#include "fm_picture_widget.h"
#include "fm_main_widget.h"

MainWidget::MainWidget(QWidget* parent) : QWidget(parent)
{
	m_width = 850;
	m_height = 600;

    // setting window size
    resize(m_width, m_height);

    // setting no border window
    setWindowFlags(Qt::FramelessWindowHint);

    // setting default background picture
    m_bkPicName = "Resources/img/skin_old_wood.jpg";

    // initialize title bar
    m_titleW = new FMTitleWidget(QStringLiteral("王管家"), this);
	connect(m_titleW, SIGNAL(doSkin()), this, SLOT(doChangeSkin()));
	connect(m_titleW, SIGNAL(doSetting()), this, SLOT(doSetting()));
	connect(m_titleW, SIGNAL(doMin()), this, SLOT(showMinimized()));
    connect(m_titleW, SIGNAL(doMax()), this, SLOT(doMax()));
	connect(m_titleW, SIGNAL(doFullScreen()), this, SLOT(showFullScreen()));
	connect(m_titleW, SIGNAL(doReturnSrcScreem()), this, SLOT(doReturnSrcScreem()));
	connect(m_titleW, SIGNAL(doClose()), this, SLOT(doExit()));

	// add skin
	m_skinW = new FMSkinWidget(m_bkPicName, this);
	connect(m_skinW, SIGNAL(changeSkin(QString)), this, SLOT(setPicName(QString)));
	m_skinW->addSkin(QStringLiteral("愤怒的小鸟"), "Resources/img/skin_angry_bird.jpg");
	m_skinW->addSkin(QStringLiteral("优雅爵士"), "Resources/img/skin_black_point.jpg");
	m_skinW->addSkin(QStringLiteral("蓝色天空"), "Resources/img/skin_blue_sky.jpg");
	m_skinW->addSkin(QStringLiteral("经典皮肤"), "Resources/img/skin_classic.jpg");
	m_skinW->addSkin(QStringLiteral("青青世界"), "Resources/img/skin_green_world.jpg");
	m_skinW->addSkin(QStringLiteral("古典木纹"), "Resources/img/skin_old_wood.jpg");
	m_skinW->addSkin(QStringLiteral("粉色之恋"), "Resources/img/skin_pink_love.jpg");
	m_skinW->addSkin(QStringLiteral("红色惊雷"), "Resources/img/skin_red_thunder.jpg");
	m_skinW->addSkin(QStringLiteral("卫士六周年"), "Resources/img/skin_six_years.jpg");
    
    // initialize tool bar 
    m_toolW = new FMToolWidget(this);
	m_toolW->addToolBtnStart();
	m_toolW->addToolBtn("Resources/img/tool_account.png", QStringLiteral("密码管家"));
	m_toolW->addToolBtn("Resources/img/tool_pic.png", QStringLiteral("家庭图片"));
	m_toolW->addToolBtnEnd();

	connect(m_toolW, SIGNAL(contentChange(QString)), this, SLOT(contentChange(QString)));

	m_accountWidget = new FMAccountWidget(this);
	m_pictureWidget = new FMPictureWidget(this);

    // setting content layout
	m_stackedLayout = new QStackedLayout();
	m_stackedLayout->invalidate();
	m_stackedLayout->addWidget(m_accountWidget);
	m_stackedLayout->addWidget(m_pictureWidget);

	m_stackedLayout->setCurrentWidget(m_accountWidget);

	m_contentWidgetMap.insert(QStringLiteral("密码管家"), m_accountWidget);
	m_contentWidgetMap.insert(QStringLiteral("家庭图片"), m_pictureWidget);

    // initialize status bar
	m_statusW = new FMStatusWidget(this);

    // setting outermost layer layout
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(1, 0, 1, 0);
    m_mainLayout->addWidget(m_titleW);
    m_mainLayout->addWidget(m_toolW);
	m_mainLayout->addLayout(m_stackedLayout);
    m_mainLayout->addWidget(m_statusW);

    // addition main widget layout
    setLayout(m_mainLayout);
}

void MainWidget::paintEvent(QPaintEvent *)
{
    QBitmap bitmap(this->size());
    bitmap.fill();
    QPainter painter(&bitmap);
    painter.setBrush(QBrush(Qt::black));
    painter.drawRoundedRect(bitmap.rect(), 5, 5);
    setMask(bitmap);

    QPixmap pixmap(this->size());
    pixmap.fill();
    painter.end();
    painter.begin(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing, true);
    QBrush brush;
    brush.setStyle(Qt::TexturePattern);
    brush.setTextureImage(QImage(m_bkPicName));
    painter.setBrush(brush);
    painter.setPen(Qt::black);
    painter.drawRoundedRect(rect(), 5, 5);
    painter.end();
    painter.begin(this);
    painter.drawPixmap(this->rect(), pixmap);
}

void MainWidget::doChangeSkin()
{
	QPoint p = rect().topRight();
	p.setX(p.x() - 150 - 350);
	p.setY(p.y() + 30);

	m_skinW->move(this->mapToGlobal(p));
	m_skinW->show();
}

void MainWidget::doSetting()
{

}

void MainWidget::doMax()
{
	static bool isMax = false;

	if (isMax)
	{
		doReturnSrcScreem();
		isMax = false;
	}
	else
	{
		setGeometry(QApplication::desktop()->availableGeometry());
		isMax = true;
	}
}

void MainWidget::doReturnSrcScreem()
{
	QPoint normalTopLeft(QApplication::desktop()->availableGeometry().width() / 2 - m_width / 2,
		QApplication::desktop()->availableGeometry().height() / 2 - m_height / 2);

	move(normalTopLeft);
	resize(m_width, m_height);
}

void MainWidget::doExit()
{
	qApp->quit();
}

void MainWidget::setPicName(QString picName)
{
    m_bkPicName = picName;
    update();
}

void MainWidget::contentChange(QString name)
{
	for (auto iter = m_contentWidgetMap.begin(); iter != m_contentWidgetMap.end(); ++iter)
	{
		if (iter.key() == name)
		{
			m_stackedLayout->setCurrentWidget(iter.value());
			break;
		}
	}
}