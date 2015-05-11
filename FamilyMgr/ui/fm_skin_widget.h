/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_skin_widget.h
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
#include <QWidget>

typedef QMap<QString, QString> SkinMap;

class QGridLayout;

class FMSkinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FMSkinWidget(QString picName, QWidget* parent = 0);
	void addSkin(QString picPath, QString name);
    
signals:
    void changeSkin(QString);

private slots:
    void setSkin(QString);

protected:
    void paintEvent(QPaintEvent*);

private:
    QString m_bkPicName;
	SkinMap m_skinMap;
	QGridLayout* m_gridLayout;
	QSignalMapper* m_signalMapper;
};
