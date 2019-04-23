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

} // namespace Paint

