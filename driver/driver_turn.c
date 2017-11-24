

#include <stdio.h>
#include <stdlib.h>
#include "../turn.h"

void pause(void){
    printf("\n");
    system("pause");
}

int main (void){


    printf(">>>>>> TESTING : Create_turn"); pause();
    Queue TURN;

    printf("\nBEFORE :\n");
    queue_PrintQ(TURN);
    TURN = Create_turn();

    printf("\nCreating empty queue...\n");
    printf("function should : create empty queue\n");
    printf("\nAFTER :\n");
    queue_PrintQ(TURN);

    printf("\n\n>>>>>> TESTING : Create_turn complete \n");
    printf("===========================================================================================\n");

    printf(">>>>>> TESTING : Setup turn");pause();
    printf("\nBEFORE : \n");
    queue_PrintQ(TURN);

    printf("\n\nsetting up turn for 2 players...\n");
    printf("function should : generate random sequence of player at odds index\n");
    printf("function should : keep track of current turn using even index \n");

    Setup_turn(&TURN, 2);
    printf("\nAFTER : \n");

    int Player,turn;
    queue_PrintQ(TURN);
    queue_Del(&TURN, &Player);
    queue_Del(&TURN, &turn);
    printf("turn %d -> player %d's turn\n",turn, Player);

    queue_Del(&TURN, &Player);
    queue_Del(&TURN, &turn);
    printf("turn %d -> player %d's turn\n",turn, Player);

    printf("\n\n>>>>>> TESTING : Setup turn complete \n");
    printf("===========================================================================================\n");

    printf(">>>>>> TESTING : Switch turn");pause();
    printf("\nBEFORE : \n");
    Setup_turn(&TURN, 2);

    Queue TURNCOPY = TURN;

    queue_Del(&TURNCOPY, &Player);
    queue_Del(&TURNCOPY, &turn);
    printf("turn %d -> player %d's turn\n",turn, Player);

    queue_Del(&TURNCOPY, &Player);
    queue_Del(&TURNCOPY, &turn);
    printf("turn %d -> player %d's turn\n",turn, Player);

    printf("\n\nsetting up turn for 2 players...\n");
    printf("function should : add current player to end of queue\n");
    printf("function should : keep track of turn order \n\n");

    int Current_player;
    Switch_turn(&TURN, &Current_player);
    printf("\nAFTER : \n");

    queue_Del(&TURN, &Player);
    queue_Del(&TURN, &turn);
    printf("turn %d -> player %d's turn\n",turn, Player);

    queue_Del(&TURN, &Player);
    queue_Del(&TURN, &turn);
    printf("turn %d -> player %d's turn\n",turn, Player);

    printf("\n\n>>>>>> TESTING : Switch turn complete \n");
    printf("===========================================================================================\n");

    return 0;
}

