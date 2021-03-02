#ifndef QMLPATH_H
#define QMLPATH_H

#include <QObject>
#include <QPainterPath>

/**
 * @brief 封装路径
 * @author 龚建波
 * @date 2021-3-2
 */
class QmlPath : public QObject
{
    Q_OBJECT
public:
    explicit QmlPath(QObject *parent = nullptr);
    ~QmlPath();

    QPainterPath getPath() const { return path; }

    Q_INVOKABLE void clearPath();
    Q_INVOKABLE void moveTo(qreal x, qreal y);
    Q_INVOKABLE void lineTo(qreal x, qreal y);
    Q_INVOKABLE void closeSubpath();
    Q_INVOKABLE void addEllipse(qreal x, qreal y, qreal rx, qreal ry);
    Q_INVOKABLE void addRect(qreal x, qreal y, qreal width, qreal heigh);

private:
    QPainterPath path;
};

#endif // QMLPATH_H
