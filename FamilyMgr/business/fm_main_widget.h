/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_main_widget.h
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

#include <QMap>
#include <QtWidgets/QWidget>
#include <QStackedLayout>

class FMTitleWidget;
class FMToolWidget;
class FMStatusWidget;
class FMAccountWidget;
class FMSkinWidget;
class FMPictureWidget;
class FMContentWidget;

typedef QMap<QString, FMContentWidget*> FMContentWidgetMap;

class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    MainWidget(QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent*);

private slots:
	void doChangeSkin();
	void doSetting();
    void doMax();
	void doReturnSrcScreem();
    void doExit();
    void setPicName(QString);
	void contentChange(QString);

private:
	quint32 m_width;
	quint32 m_height;
	QString	m_bkPicName;

	FMTitleWidget* m_titleW;
	FMToolWidget* m_toolW;
	QStackedLayout*	m_stackedLayout;
	FMStatusWidget* m_statusW;
	QVBoxLayout* m_mainLayout;
	FMSkinWidget* m_skinW;
	FMAccountWidget* m_accountWidget;
	FMPictureWidget* m_pictureWidget;
	FMContentWidgetMap m_contentWidgetMap;
};
