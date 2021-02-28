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

    qDebug()<<"main"<<QThread::currentThread();
    connect(this, &QQuickItem::windowChanged,
            this, [this](QQuickWindow *window){
        if (window){
            connect(window,&QQuickWindow::beforeSynchronizing,this,[this](){
                qDebug()<<"before sync"<<QThread::currentThread();
            },Qt::DirectConnection);
            connect(window,&QQuickWindow::afterSynchronizing,this,[this](){
                qDebug()<<"after sync"<<QThread::currentThread();
            },Qt::DirectConnection);
        }
    });
}

QmlCanvas::~QmlCanvas()
{

}

void QmlCanvas::updatePolish()
{
    qDebug()<<"update polish"<<QThread::currentThread();
    QPainter painter(&image);
    if(painter.isActive()){
        image.fill(QColor(255,0,0,150));
    }
}

QSGNode *QmlCanvas::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *data)
{
    qDebug()<<"node change"<<QThread::currentThread();
    Q_UNUSED(data)
    QSGImageNode *node = static_cast<QSGImageNode *>(oldNode);
    if (!node) {
        node = window()->createImageNode();
    }

    if(!image.isNull()){
        //QMetaObject::invokeMethod(this,&QmlCanvas::paint,Qt::QueuedConnection);
        QSGTexture *texture = window()->createTextureFromImage(image);
        node->setRect(boundingRect());
        //qDebug()<<boundingRect()<<texture->textureSize();
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
        polish();
        update();
    }
}
