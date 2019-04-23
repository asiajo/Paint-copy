#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include "action.h"
#include "drawable.h"
#include "scribble.h"
#include <functional>
#include <memory>
#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QPainter>

namespace Paint
{
class ScribbleArea : public QWidget
{
    Q_OBJECT

public:

    typedef std::shared_ptr<Drawable> drawableType;

    ScribbleArea(QWidget *parent = 0);
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    void setDrawable(drawableType drawable);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void clearImage();
    void print();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified = false;
    bool scribble = false;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPainter painter;
    drawableType _drawable;
};
} // namespace Paint
#endif
