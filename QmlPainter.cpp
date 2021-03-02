#include "QmlPainter.h"

#include <QtMath>
#include <QDebug>

QmlPainter::QmlPainter(QImage *image)
    : painter(image)
{
}

QmlPainter::~QmlPainter()
{

}

bool QmlPainter::isActive() const
{
    return painter.isActive();
}

QmlPath *QmlPainter::createPath()
{
    return new QmlPath(this);
}

void QmlPainter::save()
{
    painter.save();
}

void QmlPainter::restore()
{
    painter.restore();
}

void QmlPainter::setPen(const QColor &color, int width)
{
    painter.setPen(QPen(color,width));
}

void QmlPainter::setAntialiasing(bool on)
{
    painter.setRenderHint(QPainter::Antialiasing,on);
}

void QmlPainter::setClipPath(QmlPath *path)
{
    if(path){
        painter.setClipPath(path->getPath());
    }
}

void QmlPainter::drawPath(QmlPath *path)
{
    if(path){
        painter.drawPath(path->getPath());
    }
}

void QmlPainter::fillPath(QmlPath *path, const QColor &fillColor)
{
    if(path){
        painter.fillPath(path->getPath(),fillColor);
    }
}

void QmlPainter::drawLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    painter.drawLine(QPointF(x1,y1),QPointF(x2,y2));
}
