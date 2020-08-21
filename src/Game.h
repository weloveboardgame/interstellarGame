#include "libnet-sample.h"
#include <pcap.h>
#include <stdio.h>
#include <netinet/in.h>

class Game{
    
    public:
        Game();
        void updateStones(int x, int y, int team);
        void disableBtn();
        void playButton(int i);
        void readStones();
        bool putMyStone(int sel);
        void showStones();
        int waitNextTurn();        

        int grav;
        char* dev;
        pcap_t* handle;

    private:
        int stoneStatus[7][7];

};