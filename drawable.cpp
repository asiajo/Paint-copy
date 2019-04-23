#include "drawable.h"

namespace Paint
{

void Drawable::startDrawing()
{
    start.setX(0);
    start.setY(0);
}

void Drawable::stopDrawing()
{
    end.setX(0);
    end.setY(0);
}

void Drawable::updatePosition(const QPoint &toPoint)
{
    if (start.isNull())
        start = toPoint;
    if (end.isNull())
        end = toPoint;
}

} // namespace Paint

