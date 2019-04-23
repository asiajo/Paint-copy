#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "drawable.h"
#include <QLine>
#include <QPoint>

namespace Paint
{

class Scribble : public Drawable
{
protected:
    virtual void draw(QPainter &painter) override;
    virtual void updatePosition(const QPoint &toPoint) override;

private:
    QPoint start;
    QPoint end;
};

} //namespace Paint
#endif // SCRIBBLE_H


