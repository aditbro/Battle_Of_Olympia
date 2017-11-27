#include "../map/map.h"
#include "../offbattle/offbattle.h"
#include "../unit/unit.h"
#include "../unit_battle/unit_battle.h"
#include "../move/move.h"
#include "../recruit/recruit.h"
#include "../turn/turn.h"
#include "../player/player.h"
#include "villagelist.h"
#include "../unitlist/unitlist.h"
#include "../ADT/jam.h"
#include "../ADT/mesinkata.h"

#include <stdio.h>

boolean isKataCommand(Kata kata1,char *input){
	int i=1;
	boolean sama=true;
	while(sama && i<=kata1.Length){
		if(kata1.TabKata[i]!=input[i-1]){
			sama=false;
		}
		i++;
	}
	return sama;
}


int main() {
	Kata move,Undo,change,recruit,Attack,map,info,end,save,Exit,load,next,status;
	move.TabKata[1]='M';
	move.TabKata[2]='O';
	move.TabKata[3]='V';
	move.TabKata[4]='E';
	move.Length=4;
	Undo.TabKata[1]='U';
	Undo.TabKata[2]='N';
	Undo.TabKata[3]='D';
	Undo.TabKata[4]='O';
	Undo.Length=4;
	change.TabKata[1]='C';
	change.TabKata[2]='H';
	change.TabKata[3]='A';
	change.TabKata[4]='N';
	change.TabKata[5]='G';
	change.TabKata[6]='E';
	change.TabKata[7]='_';
	change.TabKata[8]='U';
	change.TabKata[9]='N';
	change.TabKata[10]='I';
	change.TabKata[11]='T';
	change.Length=11;
	recruit.TabKata[1]='R';
	recruit.TabKata[2]='E';
	recruit.TabKata[3]='C';
	recruit.TabKata[4]='R';
	recruit.TabKata[5]='U';
	recruit.TabKata[6]='I';
	recruit.TabKata[7]='T';
	recruit.Length=7;
	recruit.TabKata[1]='R';
	Attack.TabKata[1]='A';
	Attack.TabKata[2]='T';
	Attack.TabKata[3]='T';
	Attack.TabKata[4]='A';
	Attack.TabKata[5]='C';
	Attack.TabKata[6]='K';
	Attack.Length=6;
	map.TabKata[1]='M';
	map.TabKata[2]='A';
	map.TabKata[3]='P';
	map.Length=3;
	info.TabKata[1]='I';
	info.TabKata[2]='N';
	info.TabKata[3]='F';
	info.TabKata[4]='O';
	info.Length=4;
	end.TabKata[1]='E';
	end.TabKata[2]='N';
	end.TabKata[3]='D';
	end.TabKata[4]='_';
	end.TabKata[5]='T';
	end.TabKata[6]='U';
	end.TabKata[7]='R';
	end.TabKata[8]='N';
	end.Length=8;
	save.TabKata[1]='S';
	save.TabKata[2]='A';
	save.TabKata[3]='V';
	save.TabKata[4]='E';
	save.Length=4;
	load.TabKata[1]='L';
	load.TabKata[2]='O';
	load.TabKata[3]='A';
	load.TabKata[4]='D';
	load.Length=4;
	Exit.TabKata[1]='E';
	Exit.TabKata[2]='X';
	Exit.TabKata[3]='I';
	Exit.TabKata[4]='T';
	Exit.Length=4;
	next.TabKata[1]='N';
	next.TabKata[2]='E';
	next.TabKata[3]='X';
	next.TabKata[4]='T';
	next.Length=4;
	status.TabKata[1]='S';
	status.TabKata[2]='T';
	status.TabKata[3]='A';
	status.TabKata[4]='T';
	status.TabKata[5]='U';
	status.TabKata[6]='S';
	status.Length=6;
	Show_title();

	boolean dummy = true;

	/* Initialization */
	Player player_1 = create_new_player(1);
	Player player_2 = create_new_player(2);
	Player* Current_player; int Current_player_int;

	MAP M = Init_map();
	Queue TURN = Init_turn();

	Init_game(&M, &player_1, &player_2);

	UNIT Dummy_unit = Create_new_unit('Z', 0, 0, 0); // dummy unit
	UNIT* Current_unit = &Dummy_unit;

	char input[100] = "END_TURN"; //automatic start first turn
	int i, j;
	Display_village_list(M, villages(player_1));
	Display_village_list(M, villages(player_2));
	printMap(M);
	scannf("%d %d", &i, &j);
	Insert_village(villages(player_1),Build(M,i,j).position, 1);
	printMap(M);
}