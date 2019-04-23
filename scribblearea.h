#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include "action.h"
#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QPainter>

namespace Paint {
class ScribbleArea : public QWidget
{
    Q_OBJECT

public:
    ScribbleArea(QWidget *parent = 0);

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    void enableDrawPen();
    void enableDrawLine();
    void enableDrawCircle();
    void enableDrawRectangle();
    void enableFill();

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
    void drawPen(const QPoint &endPoint);
    void drawScribbleLine(const QPoint &endPoint);
    void drawCircle(const QPoint &endPoint);
    void drawRectangle(const QPoint &endPoint);
    void fill(QMouseEvent *event);

    bool modified;
    bool scribbling;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    Action currentAction;
    QPoint actualStartPoint;
    QPainter painter;
};
} // namespace Paint
#endif
