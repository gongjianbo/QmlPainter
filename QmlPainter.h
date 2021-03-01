#ifndef QMLPAINTER_H
#define QMLPAINTER_H

#include <QObject>
#include <QPainter>
#include <QImage>

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

    bool isActive() const;

public slots:
    void setAntialiasing(bool on = true);
    //
    void drawLine(qreal x1, qreal y1, qreal x2, qreal y2);

private:
    QPainter painter;
};

#endif // QMLPAINTER_H
