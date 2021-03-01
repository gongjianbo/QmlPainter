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

void QmlPainter::setAntialiasing(bool on)
{
    painter.setRenderHint(QPainter::Antialiasing,on);
}

void QmlPainter::drawLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    painter.drawLine(QPointF(x1,y1),QPointF(x2,y2));
}
