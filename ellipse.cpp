#include "ellipse.h"

namespace Paint {

void Ellipse::startDraw(QPainter &painter)
{

}
void Ellipse::dragDraw(QPainter &painter)
{
    // implement showing temporary Ellipse
}

void Ellipse::stopDraw(QPainter &painter)
{
    int x = start.rx();
    int y = start.ry();
    int width = end.rx() - x;
    int height = end.ry() - y;
    painter.drawEllipse(x, y, width, height);
}

} // namespace Paint
