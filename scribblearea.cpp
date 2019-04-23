#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif

#include "scribblearea.h"

namespace Paint
{
ScribbleArea::ScribbleArea(QWidget *parent)
    : QWidget(parent), myPenWidth(3), myPenColor(Qt::black)
{
    setAttribute(Qt::WA_StaticContents);  
}


bool ScribbleArea::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat))
    {
        modified = false;
        return true;
    } else
    {
        return false;
    }
}

void ScribbleArea::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

void ScribbleArea::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void ScribbleArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = false;
    update();
}

void ScribbleArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        scribble = true;
    modified = true;
    painter.begin(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    if(!_drawable)
        _drawable = std::make_shared<Scribble>();

    _drawable -> startDrawing();
    _drawable -> updatePosition(event->pos());
    _drawable -> startDraw(painter);
    repaint();
    }
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
    if(scribble)
    {
    _drawable -> updatePosition(event->pos());
    _drawable -> dragDraw(painter);
    repaint();
    }
}

void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
    if(scribble)
    {
    _drawable -> stopDrawing();
    _drawable -> updatePosition(event->pos());
    _drawable -> stopDraw(painter);
    repaint();
    painter.end();
    scribble = false;
    }
}

void ScribbleArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void ScribbleArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void ScribbleArea::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void ScribbleArea::print()
{
#if QT_CONFIG(printdialog)
    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0, 0, image);
    }
#endif // QT_CONFIG(printdialog)
}

void ScribbleArea::setDrawable(drawableType drawable)
{
    _drawable = drawable;
}

} // namespace Paint
