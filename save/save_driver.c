#include "../map/map.h"
#include "../offbattle/offbattle.h"
#include "../unit/unit.h"
#include "../unit_battle/unit_battle.h"
#include "../move/move.h"
#include "../recruit/recruit.h"
#include "../turn/turn.h"
#include "../player/player.h"
#include "../unitlist/unitlist.h"
#include "../ADT/jam.h"
#include "../ADT/mesinkata.h"
#include "save.h"

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
	int jalan = 0;
	while (!isKataCommand(Exit,input) && jalan < 3) {
		if (isKataCommand(map,input)) {
			/* Print map */
			printMap(M);
		}

		else if (isKataCommand(Attack,input)) {
			/* Command to declare attack using current unit */
			boolean Win,Lose;
			attack(Current_unit, &M, &Win,&Lose);
			if(Win){
				printf("You Win\n");
				break;
			}
			if(Lose){
				printf("You Lose\n");
				break;
			}
		}

		else if (isKataCommand(move,input)) {
			/* Command to move unit */
			int x, y;
			//move rejected when you tried move unit that max mov ==0
			if (Mov(*Current_unit) != 0) {
				print_possible_move(M, *Current_unit);
				printf("Moving into : ");
				scanf("%d %d", &x, &y);
				if (check_if_possible(M, *Current_unit, x, y)) {

					int unit_index_in_list;
					units(*Current_player) = change_unit_position_pre(units(*Current_player), Current_unit, &unit_index_in_list);
					move_unit(&player_1,&player_2,&M, Current_unit, x, y);
					units(*Current_player) = change_unit_position_post(units(*Current_player), Current_unit, unit_index_in_list);

					printf("Unit moved\n");

				}
				else {
					printf("\nThat unit can't be placed there...\n");
				}
			}
			else {
				printf("You can't move anymore\n");
			}
		}
		else if (isKataCommand(change,input)) {
			/* Switching current unit */

			refreshMap(&M,units(*Current_player));
			int unit_list_index;
			Display_unit_list(M, units(*Current_player));
			printf("Switching into unit : ");
			scanf("%d", &unit_list_index);
			select_unit(&M, units(*Current_player), Current_unit, unit_list_index);
			call_move();
		}

		else if (isKataCommand(next,input)) {
			/* Switching current next unit */

			refreshMap(&M,units(*Current_player));
			int next_unit_idx = search_next_unit(&M, units(*Current_player), Current_unit);
			if(next_unit_idx != -999){
                select_unit(&M, units(*Current_player), Current_unit, next_unit_idx);
                call_move();
			}
			else{
                printf("\nNo more unit to move nor attack...\n");
			}
		}


		else if (isKataCommand(recruit,input)) {
			/* Recruit unit */

			recruit_unit(&M, Current_player, *Current_unit);

		}

		else if (isKataCommand(info,input)) {
			/* Show info of specific tile */

			printInfo(M);
		}

		else if (isKataCommand(status,input)) {
			/* Show current unit info */

			printf(" ========================\n");
			printf("|    Player %d's Unit     |\n", Owner(*Current_unit));
			printf(" ========================\n");
			Show_unit_info(*Current_unit);
			printf("\n");
		}

		else if (isKataCommand(end,input)) {
			/* End turn */
			if (!dummy) {
				gold(*Current_player) = gold(*Current_player) - upkeep(*Current_player);
				gold(*Current_player) = gold(*Current_player) + income(*Current_player);
				refresh_unit_list(&M, units(*Current_player));
				do_heal(&M, units(*Current_player));

			}
			else {
				dummy = false;
			}

			Switch_turn(&TURN, &Current_player_int);
			if (Current_player_int == 1) {
				Current_player = &player_1;
				Current_unit = &Dummy_unit;
				strcpy(input, "End");
			}
			else if (Current_player_int == 2) {
				Current_player = &player_2;
				Current_unit = &Dummy_unit;
				strcpy(input, "End");
			}
			printf("Cash: %dG | Income: %dG | Upkeep: %dG\n", gold(*Current_player), income(*Current_player), upkeep(*Current_player));
			printf("\nPlease change your unit first!\n");
			// increase gold , decrease gold , healing

		}
		else if (isKataCommand(Undo,input)) {

			int unit_index_in_list;
			units(*Current_player) = change_unit_position_pre(units(*Current_player), Current_unit, &unit_index_in_list);
			undo(&player_1,&player_2,&M, Current_unit);
			units(*Current_player) = change_unit_position_post(units(*Current_player), Current_unit, unit_index_in_list);
		}
		else if (isKataCommand(save,input)) {
			printf("Save current game? (y/n)\n");

			print_red('!');
			printf("! Saving your game will result in ending your current turn.\n");
			scanf("%s", input);
			if (strcmp(input, "y") == 0) {
				printf("Saving game... \n");
				saveMap(M);
				print_JAM();
				printf("Saved.\n");
				
			}
			else {
				printf("Canceled.\n");
			}
		}
		else if (isKataCommand(load,input)) {
			printf("Load previous saved game?(y/n)\n");
			printf("Be careful! You'll lost your current game.\n");
			scanf("%s", input);
			if (strcmp(input, "y") == 0) {
				printf("Loading game.. \n");
				loadMap(&M);
				printf("Loaded.\n");
			}
			else {
				printf("Canceled.\n");
			}
		}

		/* Get new input */
		printf("\ninput your next command ! >> ");
		scanf("%s", input);
		printf("\n");
		jalan++;
	}
	SaveGame(player_1,player_2);
	LoadGame(player_1,player_2);
	printf("Cash: %dG | Income: %dG | Upkeep: %dG\n", gold(player_1), income(player_1), upkeep(player_1));
	printf("\nPlease change your unit first!\n");
}
