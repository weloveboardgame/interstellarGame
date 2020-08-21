#ifndef IGWINDOW_H
#define IGWINDOW_H

#include <QMainWindow>
#include "gravityD.h"
#include "QLabel"

QT_BEGIN_NAMESPACE
namespace Ui { class IGWindow; }
QT_END_NAMESPACE

class IGWindow : public QMainWindow
{
    Q_OBJECT

public:
    IGWindow(QWidget *parent = nullptr);
    void setStones();
    ~IGWindow();

private slots:
    static int stoneStatus[7][7];
    static QLabel stoneList[7][7];
    static QPixmap btnImg[3];

    bool checkStones(gravityD gd, int sel);
    void updateStones(int x, int y, int team);
    void disableBtn(gravityD gd);

    void on_pushButton_13_clicked();

    void on_select_1_clicked();

    void on_select_2_clicked();

    void on_select_3_clicked();

    void on_select_7_clicked();

    void on_select_4_clicked();

    void on_select_5_clicked();

    void on_select_6_clicked();

    void on_p15_2_windowIconChanged(const QIcon &icon);

private:
    Ui::IGWindow *ui;
};
#endif // IGWINDOW_H
