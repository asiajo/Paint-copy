#ifndef ELLIPSE_H
#define ELLIPSE_H


#include "drawable.h"

namespace Paint
{
class Ellipse : public Drawable
{
public:

    virtual void startDraw(QPainter &painter) override;
    virtual void dragDraw(QPainter &painter) override;
    virtual void stopDraw(QPainter &painter) override;
};

} // namespace Paint
#endif // ELLIPSE_H
