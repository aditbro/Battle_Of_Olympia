
/* Module handling player's turns */

#ifndef TURN_H
#define TURN_H

#include "ADT/queue.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/* NOTES :

    - in main program, use :
        Queue Player_turn_queue = Init_turn();

    - switch_turn should be called when player's end his/her turn
        Switch_turn(&Player_turn_queue, &Current_player);

*/

Queue Create_turn();
/* Function to return queue for storing player's turn */

void Setup_turn(Queue *Queue_turn, int Player_count);
/* Procedure to generate random sequences of player's turn */

Queue Init_turn();
/* Function to return ready-to-use player's turn queue */

void Switch_turn(Queue *Queue_turn, int *Current_player);
/* Function to switch turn, and print next player's turn (call upon end turn) */


#endif
