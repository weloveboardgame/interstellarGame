#include "Game.h"
#include <stdio.h>
#include "libnet-sample.h"
#define ETHERNET_LENGTH 14
#define IP_LENGTH       20
#define TCP_LENGTH      20
#define TCP_CHECK       6

Game::Game(){
    for (int i = 0 ; i <7; i++)
        for(int j =0 ; j <7 ; j++)
            stoneStatus[i][j] = 0;
    grav = 2;
    dev = "eth0";
}

void Game::updateStones(int i, int j, int team){
    stoneStatus[i][j] = team;
}

void Game::readStones(){
    for(int i = 0 ; i < 7 ; i++)
        for (int j = 0 ; j < 7 ; j++){
            if (stoneStatus[i][j] != 0){
                updateStones(i, j, stoneStatus[i][j]);
            }
        }
}

bool Game::putMyStone(int sel){

    int i;
    switch(static_cast<int>(grav)){
    // North
    case(0):
        for(i=6 ; i >=0 ; i--){
            if (stoneStatus[i][sel] == 0 ){
                stoneStatus[i][sel] = 1;
                updateStones(sel, i, 1);
                return true;
            }
        }
        break;

    // East
    case(1):
        for(i=6 ; i >=0 ; i--){
            if (stoneStatus[sel][i] == 0 ){
                stoneStatus[sel][i] = 1;
                updateStones(sel, i, 1);
                return true;
            }
        }
        break;

    // South
    case(2):
        for(i=0 ; i <7 ; i++){
            if (stoneStatus[i][sel] == 0 ){
                stoneStatus[i][sel] = 1;
                updateStones(i, sel, 1);
                return true;
            }
        }
        break;
    // West
    case(3):
        for(i=0 ; i <7 ; i++){
            if (stoneStatus[sel][i] == 0 ){
                stoneStatus[sel][i] = 1;
                updateStones(sel, i, 1);
                return true;
            }
        }
        break;
    }
    return false;

}

void Game::playButton(int i){
    if (putMyStone(i) == false){
        printf("you can't put there");
    };
    showStones();
}

void printLine(){

    printf("  |");
    for (int i=0; i<21 ; i++){
        printf("=");
    }
    printf("|");

    printf("\n");
}
void printNum(){
    int i;

    printf("  |");
    for (int i =0 ; i<7 ; i++){
        printf("%2d ", i);
    }
    printf("|\n");

}

void Game::showStones(){
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printLine();
    for (int i = 0 ; i <7 ; i++){
        printf("%2d|", i);
        for (int j=0 ; j<7 ; j++){
            printf("%2d ", stoneStatus[i][j]);
        }
        // printf("|%d", i);
        printf("|");
        printf("\n");
    }

    printLine();
    printNum();
}

int Game::waitNextTurn(){
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    
    if (handle == nullptr) {
        fprintf(stderr, "pcap_open_live(%s) return nullptr - %s\n", dev, errbuf);
        return -1;
    }

    while (true) {
        struct pcap_pkthdr* header;
        const u_char*       packet;
        const ethernet_hdr* ethernet;
        const ipv4_hdr*     ip;
        const tcp_hdr*      tcp;
        u_char*          payload;

        payload[16] ={0, };

        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;
        if (res == -1 || res == -2) {
            printf("pcap_next_ex return %d(%s)\n", res, pcap_geterr(handle));
            break;
        }
        
        printf("\n%u bytes captured\n", header->caplen);
        
        ethernet = (ethernet_hdr *)(packet);
        
        ip = (ipv4_hdr *)(packet + ETHERNET_LENGTH);
        uint16_t ip_size = ip->ip_len;
        if (ip->ip_p != TCP_CHECK){
            printf("This packet isn't TCP\n");
            continue;
        }

        tcp = (tcp_hdr *)(packet + ETHERNET_LENGTH + IP_LENGTH);
        int tcp_size = sizeof(tcp);

        payload = (u_char *)(packet + ETHERNET_LENGTH + IP_LENGTH + TCP_LENGTH);
        



        print_ethernet(ethernet);
        print_IP(ip);
        print_TCP(tcp);
        print_Payload(payload, ip);
    }

}