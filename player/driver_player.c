#include "player.h"

int main() {
	Player P;
	P = create_new_player(1);

	printf("Player : %d, %d, %d, %d\n", ID(P), gold(P), income(P), upkeep(P));
}
