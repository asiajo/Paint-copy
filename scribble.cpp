#include "scribble.h"

namespace Paint {

void Scribble::startDraw(QPainter &painter)
{
    painter.drawPoint(end);
}

void Scribble::dragDraw(QPainter &painter)
{
    painter.drawLine(start, end);
}

void Scribble::stopDraw(QPainter &painter)
{
    painter.drawLine(start, end);
}

void Scribble::updatePosition(const QPoint &toPoint)
{
    if (!end.isNull())
        start = end;
    else
        start = toPoint;
    end = toPoint;
}

} // namespace Paint
