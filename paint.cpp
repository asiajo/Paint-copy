#include "paint.h"
#include "ui_paint.h"
#include <QMessageBox>
#include <iostream>
#include <QPrinter>
#include <QPrintDialog>
#include <QCloseEvent>
#include <QInputDialog>
#include <QColorDialog>

namespace Paint
{
Paint::Paint(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Paint)
{
    ui->setupUi(this);
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);
    setWindowTitle(tr("%1[*] - %2").arg("New File", QCoreApplication::applicationName()));
    resize(1200, 800);
}

Paint::~Paint()
{
    delete ui;
}

void Paint::closeEvent (QCloseEvent *event)
{
    if (maybeSave())
        event-> accept();
    else
        event->ignore();
}

void Paint::on_actionNew_triggered()
{
    if(maybeSave())
    {
        scribbleArea -> clearImage();
        filename = "";
        fileFormat = "";
    }
    setWindowTitle(tr("%1[*] - %2").arg("New File", QCoreApplication::applicationName()));
}

void Paint::on_actionOpen_triggered()
{
    maybeSave();
    filename = QFileDialog::getOpenFileName(this, "Open the file");
    if (!filename.isEmpty())
    {
        scribbleArea -> openImage(filename);
        fileFormat = filename.right(3).toLocal8Bit();
    }
    setWindowTitle(tr("%1[*] - %2").arg(filename, QCoreApplication::applicationName()));
}

void Paint::on_actionSave_triggered()
{
    if(!filename.isEmpty())
        scribbleArea->saveImage(filename, fileFormat.constData());
    else
    {
        fileFormat = "png";
        Save_As();
    }
}

void Paint::on_actionjpg_triggered()
{
    fileFormat = "jpg";
    Save_As();
}

void Paint::on_actionpng_triggered()
{
    fileFormat = "png";
    Save_As();
}

void Paint::on_actionbmp_triggered()
{
    fileFormat = "bmp";
    Save_As();
}

bool Paint::maybeSave()
{
    if (scribbleArea->isModified())
    {
       QMessageBox::StandardButton warn = QMessageBox::warning(this, tr("Save?"),
                          tr("The image has been modified.\n"
                             "Do you want to save your changes?"),
                          QMessageBox::Save | QMessageBox::Discard
                          | QMessageBox::Cancel);

        if (warn == QMessageBox::Save)
        {
            if(!filename.isEmpty())
                on_actionSave_triggered();
            else
                on_actionpng_triggered();
            return true;
        }
        else if (warn == QMessageBox::Cancel)
            return false;
    }
    return true;
}

bool Paint::Save_As()
{
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;
    filename = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString::fromLatin1(fileFormat.toUpper()))
                               .arg(QString::fromLatin1(fileFormat)));
    if (filename.isEmpty()) {
        return false;
    } else {
        setWindowTitle(tr("%1[*] - %2").arg(filename, QCoreApplication::applicationName()));
        return scribbleArea->saveImage(filename, fileFormat.constData());
    }
}

void Paint::on_actionPrint_triggered()
{
   scribbleArea -> print();
}

void Paint::on_actionExit_triggered()
{
    if(maybeSave())
        QApplication::quit();
}


void Paint::on_actionUndo_triggered()
{

}

void Paint::on_actionRedo_triggered()
{

}

void Paint::on_actionSet_Pen_Size_triggered()
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Pen Width"),
                                        tr("Select pen width:"),
                                        scribbleArea->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        scribbleArea->setPenWidth(newWidth);
}

void Paint::on_actionSet_Pen_Color_triggered()
{
    QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
    if (newColor.isValid())
        scribbleArea->setPenColor(newColor);
}

void Paint::on_actionPen_triggered()
{
    currentDrawable = std::make_shared<Scribble>();
    scribbleArea -> setDrawable(std::move(currentDrawable));
}

void Paint::on_actionLine_triggered()
{
    currentDrawable = std::make_shared<Line>();
    scribbleArea -> setDrawable(std::move(currentDrawable));
}

void Paint::on_actionRectangle_triggered()
{

}

void Paint::on_actionElipse_triggered()
{

}

void Paint::on_actionFill_triggered()
{

}

void Paint::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "This is a program that I have made to learn QT. It bases on Scribble Example fromt the Qt Documentation. I try to develop it a little bit further.<br> Author: Joanna",
                                                                QMessageBox::Ok);
}

} // namespace Paint
