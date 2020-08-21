#ifndef IGWINDOW_H
#define IGWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class IGWindow; }
QT_END_NAMESPACE

class IGWindow : public QMainWindow
{
    Q_OBJECT

public:
    IGWindow(QWidget *parent = nullptr);
    ~IGWindow();

private slots:
    void on_pushButton_13_clicked();

    void on_select_1_clicked();

    void on_select_2_clicked();

    void on_select_3_clicked();

    void on_select_7_clicked();

    void on_select_4_clicked();

    void on_select_5_clicked();

    void on_select_6_clicked();

private:
    Ui::IGWindow *ui;
};
#endif // IGWINDOW_H
