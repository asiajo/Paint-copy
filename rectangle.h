#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "drawable.h"

namespace Paint
{
class Rectangle : public Drawable
{
public:

    virtual void startDraw(QPainter &painter) override;
    virtual void dragDraw(QPainter &painter) override;
    virtual void stopDraw(QPainter &painter) override;
};

} // namespace Paint
#endif // RECTANGLE_H
