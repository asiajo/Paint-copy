#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QColor>
#include <QPainter>
#include <QPoint>
#include <QRect>

#include <memory>
#include <iostream>

namespace Paint
{
class Drawable
{
public:
    virtual ~Drawable() = default;
    virtual void startDraw(QPainter &painter) = 0;
    virtual void dragDraw(QPainter &painter) = 0;
    virtual void stopDraw(QPainter &painter) = 0;
    virtual void updatePosition(const QPoint &toPoint);
    virtual void startDrawing();
    virtual void stopDrawing();
protected:
    QPoint start;
    QPoint end;
};

} // namespace Paint
#endif // DRAWABLE_H
