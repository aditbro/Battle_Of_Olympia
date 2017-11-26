

#include <stdio.h>
#include <stdlib.h>
#include "offbattle.h"

void pause(void){
    printf("\n");
    system("pause");
}

int main (void){


    printf(">>>>>> TESTING : show title"); pause();
    Show_title();
    printf("\n\n>>>>>> TESTING : show title complete \n");
    printf("===========================================================================================\n");

    printf(">>>>>> TESTING : Init game");pause();
    printf("preparing map (calling Init_map) for testing init game ...\n\n");
    MAP M = Init_map();
    Player player_1 = create_new_player(1);
	Player player_2 = create_new_player(2);


    printf("\nBEFORE : \n\n");
    printMap(M);

    printf("\n\n");
    printf("function should : intialize 1 tower, 4castle for each player\n");
    printf("function should : initialize random village, approx 0.06 of map tiles, and not too close to one tower (imbalance)\n");
    printf("fucntion should : initialize king of both players\n\n");

    Init_game(&M, &player_1, &player_2);
    printf("\nAFTER : \n\n");
    printMap(M);
    printf("\n\n>>>>>> TESTING : Init game complete \n");
    printf("===========================================================================================\n");


    return 0;
}
