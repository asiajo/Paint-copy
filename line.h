#ifndef LINE_H
#define LINE_H


#include "drawable.h"
#include <QLine>
#include <QPoint>

namespace Paint
{

class Line : public Drawable
{
public:

    virtual void startDraw(QPainter &painter) override;
    virtual void dragDraw(QPainter &painter) override;
    virtual void stopDraw(QPainter &painter) override;
    virtual void updatePosition(const QPoint &toPoint) override;
};

} //namespace Paint

#endif // LINE_H
