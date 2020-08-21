#include <stdio.h>
#include "Game.h"

int main (){
    Game game = Game();
    int select;

    while(1){
        game.showStones();
        scanf("%d", &select);
        if (select >6){
            printf("\nInput Error\n");
            continue;
        }
        // test();
        game.playButton(select);
    }
}

