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
    virtual void draw(QPainter &painter) = 0;
    virtual void updatePosition(const QPoint &toPoint) = 0;
    void startDrawing();
    void stopDrawing();
protected:
    bool drawing = false;
};

} // namespace Paint
#endif // DRAWABLE_H
