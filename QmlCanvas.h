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
    //主动调用polish后才会触发updatePolish，在主线程执行
    void updatePolish() override;
    //qtquick绘制，在渲染线程执行
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;
    //大小改变后更新image大小
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;

signals:
    //将画笔emit出去，槽函数拿到画笔指针绘制到image
    //void doPaint(QmlPainter *painter);

private:
    //绘制到image上再渲染
    QImage image;
};

#endif // QMLCANVAS_H
