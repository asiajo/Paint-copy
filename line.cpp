#include "line.h"

#include "line.h"

namespace Paint {

void Line::startDraw(QPainter &painter)
{
    painter.drawPoint(start);
}
void Line::dragDraw(QPainter &painter)
{
    // implement showing temporary line
}

void Line::stopDraw(QPainter &painter)
{
    painter.drawLine(start, end);
}

void Line::updatePosition(const QPoint &toPoint)
{
    if (start.isNull())
        start = toPoint;
    if (end.isNull())
        end = toPoint;
}

} // namespace Paint
