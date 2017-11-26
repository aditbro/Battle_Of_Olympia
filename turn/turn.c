
/* Module handling player's turns */

#include "turn.h"

int Player_count = 2;

Queue Create_turn(){
    /* Function to return queue for storing player's turn */

    Queue Queue_turn;

    /* Create empty queue with capability to store players and turn-counters */
    queue_CreateEmpty(&Queue_turn, Player_count*2+1);

    return Queue_turn;
}

void Setup_turn(Queue *Queue_turn, int Player_count){
    /* Procedure to generate random sequences of player's turn */

    srand (time(NULL));
    int player = 1 + rand() % Player_count;;
    int turn = 1;

    while(turn != Player_count+1){

        queue_Add(Queue_turn, player);
        queue_Add(Queue_turn, turn);

        if (player == Player_count){
            player = 1;
        }
        else{
            player++;
        }
        turn++;

    }
}

Queue Init_turn(){
    /* Function to return ready-to-use player's turn queue */

    Queue Queue_turn = Create_turn();
    Setup_turn(&Queue_turn, Player_count);

    return Queue_turn;
}

void Switch_turn(Queue *Queue_turn, int *Current_player){
    /* Function to switch turn, and print next player's turn (call upon end turn) */

    int Turn_count;

    queue_Del(Queue_turn, Current_player);
    queue_Del(Queue_turn, &Turn_count);

    printf(" =====  ~ Turn %d ~  =====\n",Turn_count);
    printf("|    Player %d's Turn     |\n",*Current_player);
    printf(" ========================\n");

    queue_Add(Queue_turn, *Current_player);
    queue_Add(Queue_turn, Turn_count + Player_count);
}
