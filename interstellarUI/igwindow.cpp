#include "igwindow.h"
#include "ui_igwindow.h"

IGWindow::IGWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IGWindow)
{
    ui->setupUi(this);
}

IGWindow::~IGWindow()
{
    delete ui;
}

bool select(int i){


    return true;
}

void IGWindow::on_select_1_clicked()
{
    select(1);

}

void IGWindow::on_select_2_clicked()
{
    select(2);

}

void IGWindow::on_select_3_clicked()
{
    select(3);
}

void IGWindow::on_select_4_clicked()
{
    select(4);

}

void IGWindow::on_select_5_clicked()
{
    select(5);

}

void IGWindow::on_select_6_clicked()
{
    select(6);
}

void IGWindow::on_select_7_clicked()
{
    select(7);
}
