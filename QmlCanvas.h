#ifndef QMLCANVAS_H
#define QMLCANVAS_H

#include <QQuickItem>
#include <QImage>
#include "QmlPainter.h"

class QmlCanvas : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
public:
    explicit QmlCanvas(QQuickItem *parent = nullptr);
    ~QmlCanvas();

    QColor getBackgroundColor() const { return backgroundColor; }
    void setBackgroundColor(const QColor &color);

protected:
    //主动调用polish后才会触发updatePolish，在主线程执行
    void updatePolish() override;
    //qtquick绘制，在渲染线程执行
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;
    //大小改变后更新image大小
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;

signals:
    //将画笔emit出去，槽函数拿到画笔指针绘制到image
    void paint(QmlPainter *painter);
    //
    void backgroundColorChanged();

public slots:
    //调用polish+update
    void repaint();

private:
    //绘制到image上再渲染
    QImage image;
    //背景色
    QColor backgroundColor{255,255,255};
};

#endif // QMLCANVAS_H
