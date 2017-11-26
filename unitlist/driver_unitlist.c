

#include <stdio.h>
#include <stdlib.h>
#include "../turn/turn.h"
#include "../map/map.h"
#include "../player/player.h"
#include "../offbattle/offbattle.h"
#include "unitlist.h"

void pause(void){
    printf("\n");
    system("pause");
}

int main (void){

    printf("Creating map, player and init map for testing purpose...\n\n");
    MAP M = Init_map();
    Player player_1 = create_new_player(1);
	Player player_2 = create_new_player(2);
    Init_game(&M, &player_1, &player_2);

	UnitList UNITLIST = NULL;

    printf("\n>>>>>> TESTING : insert unit ,display unit in list ,show unit in list"); pause();

    printf("\nAdding dummy data to unit list");
    printf("\nBEFORE :\n");
    POINT Unit_pos = MakePOINT(3,5);
    Pos(Unit(M, 3, 5)) = Unit_pos;
    UNITLIST = Insert_unit(UNITLIST, Unit_pos, 0);
    Display_unit_list(M, UNITLIST);


    printf("\nfunction insert unit should : add unit with pos <5, 5> (by position) to list\n");
    printf("function display unit should : call show unit in list, and display all unit in list \n");
    printf("function insert unit should : display some unit's info \n");
    printf("\nAFTER :\n");
    Unit_pos = MakePOINT(5,5);
    Pos(Unit(M, 5, 5)) = Unit_pos;
    UNITLIST = Insert_unit(UNITLIST, Unit_pos, 1);
    Display_unit_list(M, UNITLIST);


    printf("\n\n>>>>>> TESTING : insert unit ,display unit in list ,show unit in list complete \n");





    printf("===========================================================================================\n");
    printf(">>>>>> TESTING : change_unit_position_pre-post (include Del unit and search unit index)");pause();
    printf("\nBEFORE : \n");

    UNIT Dummy;
    int Dummy_idx;
    Type(Dummy) = 'S';
    Pos(Dummy) = MakePOINT(3,5);
    Display_unit_list(M, UNITLIST);

    printf("function should : delete unit at point 3,5 and store it's index of list \n");
    UNITLIST = change_unit_position_pre(UNITLIST, &Dummy, &Dummy_idx);

    printf("\nAFTER 1 : \n");
    Display_unit_list(M, UNITLIST);
    printf("(search index) index of unit in list was : %d\n",Dummy_idx);


    printf("\nfunction should : re add dummy unit at point 4,5 and store it with same index as previous \n");
    Pos(Dummy) = MakePOINT(4,5);
    Pos(Unit(M, 4, 5)) = MakePOINT(4,5);

    UNITLIST = change_unit_position_post(UNITLIST, &Dummy, Dummy_idx);
    printf("\nAFTER 2 : \n");
    Display_unit_list(M, UNITLIST);

    printf("\n\n>>>>>> TESTING : change_unit_position_pre-post (include Del unit and search unit index \n");







    printf("===========================================================================================\n");
    printf(">>>>>> TESTING : select_unit ");pause();
    printf("\nBEFORE : \n");

    Type(Unit(M, 4, 5)) = 'A';
    Type(Dummy) = 'A';
    Show_unit_info(Dummy);

    printf("\n\nfunction should : change unit info to unit with index 2 in list (focus on position change)\n\n");


    printf("\nAFTER : \n");
    select_unit(&M, UNITLIST, &Dummy, 2);
    Show_unit_info(Dummy);
    printf("\n\n>>>>>> TESTING : select_unit, selected_on_map_ON \n");



    printf("===========================================================================================\n");
    printf(">>>>>> TESTING : selected_on_map_ON ");pause();
    printf("\nBEFORE : \n");

    printMap(M);

    printf("\n\nselected (4,5) should glow in map\n\n");

    selected_on_map_ON(&M, &Unit(M,4,5), 1);
    printf("\nAFTER : \n");

    printMap(M);

    printf("\n\n>>>>>> TESTING : selected_on_map_ON \n");



    printf("===========================================================================================\n");
    printf(">>>>>> TESTING : UnitList_empty, UnitNbElmt, Index_Max, Tail, get_unit_position");pause();
    printf("\nBEFORE : \n");

    Display_unit_list(M, UNITLIST);

    printf("function should : display properties of unitlist\n");

    printf("\nAFTER : \n");

    printf("is empty : %d\n",UnitList_empty(UNITLIST));
    printf("list element : %d\n", UnitNbElmt(UNITLIST));
    printf("list max idx : %d\n", Index_Max(UNITLIST));
    printf("Get unit position with index 1 : "); TulisPOINT(get_unit_position(UNITLIST,1));



    printf("\n\n>>>>>> TESTING : UnitList_empty, UnitNbElmt, Index_Max, Tail, get_unit_position \n");
    printf("===========================================================================================\n");

    return 0;
}


