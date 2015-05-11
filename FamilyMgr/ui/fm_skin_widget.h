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

#include <QList>
#include <QPair>
#include <QSignalMapper>
#include <QWidget>

typedef QPair<QString, QString> SkinPair;
typedef QList<SkinPair> SkinList;

class QGridLayout;

class FMSkinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FMSkinWidget(QString picName, QWidget* parent = 0);
	void addSkin(QString name, QString picPath);
    
signals:
    void changeSkin(QString);

private slots:
    void setSkin(QString);

protected:
    void paintEvent(QPaintEvent*);

private:
    QString m_bkPicName;
	quint32 m_column;
	SkinList m_skinList;
	QGridLayout* m_gridLayout;
	QSignalMapper* m_signalMapper;
};
