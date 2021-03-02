#include "QmlPath.h"

#include <QDebug>

QmlPath::QmlPath(QObject *parent) : QObject(parent)
{
    //qDebug()<<"new path";
}

QmlPath::~QmlPath()
{
    //qDebug()<<"del path";
}

void QmlPath::clearPath()
{
    //低版本没有clear
    path=QPainterPath();
}

void QmlPath::moveTo(qreal x, qreal y)
{
    path.moveTo(x,y);
}

void QmlPath::lineTo(qreal x, qreal y)
{
    path.lineTo(x,y);
}

void QmlPath::closeSubpath()
{
    path.closeSubpath();
}

void QmlPath::addEllipse(qreal x, qreal y, qreal rx, qreal ry)
{
    path.addEllipse(QPointF(x,y),rx,ry);
}

void QmlPath::addRect(qreal x, qreal y, qreal width, qreal heigh)
{
    path.addRect(x,y,width,heigh);
}
