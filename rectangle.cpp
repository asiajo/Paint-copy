#include "rectangle.h"

namespace Paint {

void Rectangle::startDraw(QPainter &painter)
{
    painter.drawPoint(start);
}

void Rectangle::dragDraw(QPainter &painter)
{
    // implement showing temporary Rectangle
}

void Rectangle::stopDraw(QPainter &painter)
{
    int x = start.rx();
    int y = start.ry();;
    int width = end.rx() - x;
    int height = end.ry() - y;
    painter.drawRect(x, y, width, height);
}


} // namespace Paint
