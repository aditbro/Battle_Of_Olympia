#include "player.h"


void InitializeNewPlayer(Player *P, int ID){
	ID(*P) = ID;
<<<<<<< HEAD
	gold(*P) = 40;
=======
	gold(*P) = 20;
>>>>>>> 478169e362eabd5b1acd66479cad5bd0183309be
	income(*P) = 0;
	upkeep(*P) = 0;

	if (ID==1){
		color(*P) = 'R';
	}
	else if (ID==2){
		color(*P) = 'G';
	}
	else if (ID==1){
		color(*P) = 'Y';
	}
	else if (ID==1){
		color(*P) = 'B';
	}
	else if (ID==1){
		color(*P) = 'M';
	}
	else if (ID==1){
		color(*P) = 'C';
	}

	units(*P) = NULL;
	villages(*P) = NULL;

}

Player create_new_player(int ID){
	Player new_player;

	InitializeNewPlayer(&new_player, ID);
	return new_player;
}