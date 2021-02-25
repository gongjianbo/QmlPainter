#ifndef QMLCANVAS_H
#define QMLCANVAS_H

#include <QQuickItem>
#include <QImage>

class QmlCanvas : public QQuickItem
{
    Q_OBJECT
public:
    explicit QmlCanvas(QQuickItem *parent = nullptr);
    ~QmlCanvas();

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;

signals:

private:
    //绘制到image上再渲染
    QImage image;
};

#endif // QMLCANVAS_H
