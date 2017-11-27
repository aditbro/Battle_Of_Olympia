<<<<<<< HEAD
#include "recruit.h"
#include "../offbattle/offbattle.h"
#include <stdio.h>

int main() {
	Player player_1 = create_new_player(1);
	Player player_2 = create_new_player(2);
	MAP M = Init_map();

	Init_game(&M, &player_1, &player_2);
	
	UNIT U;

	recruit_unit(&M, &player_1, U);
	printMap(M);
}
=======
#include "recruit.h"
#include "../offbattle/offbattle.h"
#include <stdio.h>

int main() {
	Player player_1 = create_new_player(1);
	Player player_2 = create_new_player(2);
	MAP M = Init_map();

	Init_game(&M, &player_1, &player_2);
	
	UNIT U;

	recruit_unit(&M, &player_1, U);
	printMap(M);
}
>>>>>>> eeebc0d1b1b157f279ab4aedbb193335bd5a49da
