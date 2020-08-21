#include "igwindow.h"
#include "ui_igwindow.h"

IGWindow::IGWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IGWindow)
{
    for (int i =0 ; i <7 ; i++){
        for (int j =0 ; j < 7 ; j++){
            stoneStatus[i][j] = 0;
        }
    }

    btnImg[0].load("/icon/orangeButton.png");
    btnImg[1].load("/icon/blueButton.png");

    ui->setupUi(this);
}


IGWindow::~IGWindow()
{
    delete ui;
}

bool IGWindow::checkStones(gravityD type, int sel){
    int flag = 0;
    if (type == gravityD::WEST || type == gravityD::EAST){
        for (int i = 0; i<7 ; i ++){
            if (stoneStatus[sel][i] != 0){
                flag = 1;
                break;
            }
        }
    }

    else if (type == gravityD::SOUTH || type == gravityD::NORTH){
        for (int i=0 ; i<7 ; i++){
            if (stoneStatus[i][sel] != 0){
                flag = 1;
                break;
            }
        }
    }

    if (flag != 1 ) return false;
    return true;
}

void IGWindow::updateStones(int x, int y, int team){
    if (team != 1 || team != 0) return;
    stoneList[x][y].setPixmap(btnImg[team]);
}

void IGWindow::disableBtn(gravityD dir){
    for (int i=0 ; i<4 ; i++)
        for (int j =0 ; j < 7 ; j++){
            btnList[dir][i]->setEnabled(i==dir);
        }
}

void IGWindow::readStones(int** arg){
    for(int i = 0 ; i < 7 ; i++)
        for (int j = 0 ; j < 7 ; j++){
            if (arg[i][j] != 0){
                updateStones(i, j, arg[i][j]);
            }
        }
}

bool select(int i){


    return true;
}

void putStone(int i){

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

void IGWindow::on_p15_2_windowIconChanged(const QIcon &icon)
{

}
