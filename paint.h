#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QFileDialog>
#include "scribblearea.h"

namespace Ui {
class Paint;
}

namespace Paint {
class Paint : public QMainWindow
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = 0);
    ~Paint();

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    bool Save_As();
    void on_actionPrint_triggered();
    void on_actionExit_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionSet_Pen_Size_triggered();
    void on_actionSet_Pen_Color_triggered();
    bool maybeSave();
    void closeEvent (QCloseEvent *event) override;
    void on_actionjpg_triggered();
    void on_actionpng_triggered();
    void on_actionbmp_triggered();
    void on_actionNew_triggered();
    void on_actionAbout_triggered();
    void on_actionPen_triggered();
    void on_actionLine_triggered();
    void on_actionRectangle_triggered();
    void on_actionElipse_triggered();
    void on_actionFill_triggered();

private:
    Ui::Paint *ui;
    ScribbleArea *scribbleArea;
    QString filename;
    QByteArray fileFormat;
};
} // namespace Paint
#endif // PAINT_H
