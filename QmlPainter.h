#ifndef QMLPAINTER_H
#define QMLPAINTER_H

#include <QObject>
#include <QPainter>
#include <QImage>
#include "QmlPath.h"

/**
 * @brief 封装QPainter的部分接口
 * @author 龚建波
 * @date 2021-3-1
 */
class QmlPainter : public QObject
{
    Q_OBJECT
public:
    explicit QmlPainter(QImage *image = nullptr);
    ~QmlPainter();

    //QPainter是否可用
    Q_INVOKABLE bool isActive() const;

    //new一个路径
    Q_INVOKABLE QmlPath *createPath();

public slots:
    //保存和恢复设置
    void save();
    void restore();
    //画笔设置
    void setPen(const QColor &color, int width = 1);
    //抗锯齿
    void setAntialiasing(bool on = true);
    //裁剪
    void setClipPath(QmlPath *path);
    //路径
    void drawPath(QmlPath *path);
    void fillPath(QmlPath *path, const QColor &fillColor);
    //绘制
    void drawLine(qreal x1, qreal y1, qreal x2, qreal y2);

private:
    QPainter painter;
};

#endif // QMLPAINTER_H
