#include "line.h"

namespace Paint
{

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


} // namespace Paint
