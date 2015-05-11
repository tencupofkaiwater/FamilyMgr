/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_picture_widget.cpp
* @version
* @brief
* @author   duye
* @date     2015-01-20
* @note
*
*  1. 2015-01-20 duye created this file
*
*/
#include <QPalette>
#include <QLabel>
#include <QGridLayout>

#include "fm_picture_widget.h"

FMPictureWidget::FMPictureWidget(QWidget* parent) : FMContentWidget(parent)
{
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255, 200)));
    setPalette(palette);
    setAutoFillBackground(true);
}
