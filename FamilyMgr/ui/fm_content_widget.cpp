/************************************************************************************
**
* @copyright (c) 2010-2019, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    fm_content_widget.cpp
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

#include "ui/fm_content_widget.h"

FMContentWidget::FMContentWidget(QWidget* parent) : QWidget(parent)
{
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(QColor(250, 255, 240, 150)));
    setPalette(palette);
    setAutoFillBackground(true);
}
