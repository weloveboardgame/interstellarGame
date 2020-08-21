#include "igwindow.h"
#include "ui_igwindow.h"
#include <QMessageBox>


IGWindow::IGWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IGWindow)
{
    for (int i =0 ; i <7 ; i++){
        for (int j =0 ; j < 7 ; j++){
            stoneStatus[i][j] = 0;
        }
    }

    // mine == orange
    btnImg[0].load("/icon/orangeButton.png");
    btnImg[1].load("/icon/blueButton.png");

    QPushButton* tmpButtons[4][7] = {{ui->selectW_1, ui->selectW_2, ui->selectW_3, ui->selectW_4, ui->selectW_5, ui->selectW_6, ui->selectW_7}
                               , {ui->selectR_1, ui->selectR_2, ui->selectR_3, ui->selectR_4, ui->selectR_5, ui->selectR_6, ui->selectR_13}
                               , {ui->selectS_1, ui->selectS_2, ui->selectS_3, ui->selectS_4, ui->selectS_5, ui->selectS_6, ui->selectS_7}
                               , {ui->selectL_1, ui->selectL_2, ui->selectL_3, ui->selectL_4, ui->selectL_5, ui->selectL_6, ui->selectL_7}};


    for (int i=0 ; i<4; i ++){
        memcpy(buttons[i], tmpButtons[i], sizeof(QPushButton *) * 7);
        for (int j=0 ; j<7; j ++){
            connect(buttons[i][j], SIGNAL (clicked()), this, SLOT (playButton(j)));

        }
    }

    QLabel* tmpStoneList[7][7] = {{ui->p1_1, ui->p1_2, ui->p1_3, ui->p1_4, ui->p1_5, ui->p1_6, ui->p1_7},
                               {ui->p2_1, ui->p2_2, ui->p2_3, ui->p2_4, ui->p2_5, ui->p2_6, ui->p2_7},
                               {ui->p3_1, ui->p3_2, ui->p3_3, ui->p3_4, ui->p3_5, ui->p3_6, ui->p3_7},
                               {ui->p4_1, ui->p4_2, ui->p4_3, ui->p4_4, ui->p4_5, ui->p4_6, ui->p4_7},
                               {ui->p5_1, ui->p5_2, ui->p5_3, ui->p5_4, ui->p5_5, ui->p5_6, ui->p5_7},
                               {ui->p6_1, ui->p6_2, ui->p6_3, ui->p6_4, ui->p6_5, ui->p6_6, ui->p6_7},
                               {ui->p7_1, ui->p7_2, ui->p7_3, ui->p7_4, ui->p7_5, ui->p7_6, ui->p7_7}};
    for (int i=0 ; i<7; i ++){
        memcpy(stoneimgList[i], tmpStoneList[i], sizeof(QPushButton *) * 7);
    }

    ui->setupUi(this);
}


IGWindow::~IGWindow()
{
    delete ui;
}

//bool IGWindow::checkStones(int sel){
//    int flag = 0;
//    if (grav == gravityD::WEST || grav == gravityD::EAST){
//        for (int i = 0; i<7 ; i ++){
//            if (stoneStatus[sel][i] != 0){
//                flag = 1;
//                break;
//            }
//        }
//    }

//    else if (grav == gravityD::SOUTH || grav == gravityD::NORTH){
//        for (int i=0 ; i<7 ; i++){
//            if (stoneStatus[i][sel] != 0){
//                flag = 1;
//                break;
//            }
//        }
//    }

//    if (flag != 1 ) return false;
//    return true;
//}

void IGWindow::updateStones(int x, int y, int team){
    if (team != 1 || team != 0) return;
    stoneimgList[x][y]->setPixmap(btnImg[team]);
}

void IGWindow::disableBtn(){
    int gravInt = static_cast<int>(grav);

    for (int i=0 ; i<4 ; i++)
        for (int j =0 ; j < 7 ; j++){
            buttons[gravInt][i]->setEnabled(i==gravInt);
        }
}

void IGWindow::readStones(){
    for(int i = 0 ; i < 7 ; i++)
        for (int j = 0 ; j < 7 ; j++){
            if (stoneStatus[i][j] != 0){

                updateStones(i, j, stoneStatus[i][j]);
            }
        }
}

bool IGWindow::putMyStone(int sel){
    switch(static_cast<int>(grav)){
    int i;
    // North
    case(0):
        for(i=6 ; i >=0 ; i--){
            if (stoneStatus[i][sel] == 0 ){
                stoneStatus[i][sel] = 0;
                updateStones(i, sel, 0);
                return true;
            }
        }
        break;

    // East
    case(1):
        for(i=6 ; i >=0 ; i--){
            if (stoneStatus[sel][i] == 0 ){
                stoneStatus[sel][i] = 0;
                updateStones(sel, i, 0);
                return true;
            }
        }
        break;

    // South
    case(2):
        for(i=0 ; i <7 ; i++){
            if (stoneStatus[i][sel] == 0 ){
                stoneStatus[i][sel] = 0;
                updateStones(i, sel, 0);
                return true;
            }
        }
                break;
    // West
    case(3):
        for(i=0 ; i <7 ; i++){
            if (stoneStatus[sel][i] == 0 ){
                stoneStatus[sel][i] = 0;
                updateStones(sel, i, 0);
                return true;
            }
        }
                break;
    }
    return false;

}

void IGWindow::playButton(int i){
    if (putMyStone(i) == false){
        QMessageBox m;
        m.information(nullptr, "에러", QString("해당 위치에 돌을 넣을 수 없습니다"));
    };
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
