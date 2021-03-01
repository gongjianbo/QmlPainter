#include "QmlCanvas.h"

#include <QQuickWindow>
#include <QSGImageNode>
#include <QSGTexture>
#include <QPainter>
#include <QThread>
#include <QDebug>

QmlCanvas::QmlCanvas(QQuickItem *parent)
    : QQuickItem(parent)
{
    setFlag(ItemHasContents, true);

    //在visible、size改变时update
    connect(this,&QQuickItem::visibleChanged,this,&QmlCanvas::repaint);
    //qDebug()<<"main"<<QThread::currentThread();
}

QmlCanvas::~QmlCanvas()
{

}

void QmlCanvas::setBackgroundColor(const QColor &color)
{
    backgroundColor = color;
    emit backgroundColorChanged();
    repaint();
}

void QmlCanvas::updatePolish()
{
    //qDebug()<<"update polish"<<QThread::currentThread();
    QmlPainter painter(&image);
    if(painter.isActive()){
        image.fill(backgroundColor);
        emit paint(&painter);
    }
}

QSGNode *QmlCanvas::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *data)
{
    //qDebug()<<"node change"<<QThread::currentThread();
    Q_UNUSED(data)
    QSGImageNode *node = static_cast<QSGImageNode *>(oldNode);
    if (!node) {
        //初始化时调用一次创建
        node = window()->createImageNode();
    }

    if(!image.isNull()){
        QSGTexture *texture = window()->createTextureFromImage(image);
        node->setRect(boundingRect());
        node->setSourceRect(QRect(QPoint(0,0),texture->textureSize()));
        node->setTexture(texture);
        node->setOwnsTexture(true);
        node->markDirty(QSGNode::DirtyMaterial);
    }

    return node;
}

void QmlCanvas::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    //qDebug()<<"rect change";
    QQuickItem::geometryChanged(newGeometry,oldGeometry);
    if(size().isValid()&&size().toSize()!=image.size()){
        image = QImage(size().toSize(),QImage::Format_ARGB32_Premultiplied);
        repaint();
    }
}

void QmlCanvas::repaint()
{
    polish();
    update();
}
