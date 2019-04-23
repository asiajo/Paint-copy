#include "drawable.h"

namespace Paint
{

void Drawable::startDrawing()
{
    drawing = true;
}

void Drawable::stopDrawing()
{
    drawing = false;
}

} // namespace Paint

