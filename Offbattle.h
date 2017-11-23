
#ifndef OFFBATTLE_H
#define OFFBATTLE_H

#include "ADT/matriks.h"
#include "ADT/point.h"

#include "building.h"
#include "map.h"
#include "unit.h"
#include "player_handler/unitlist.h"
#include "player_handler/player.h"

#include <stdlib.h>
#include <time.h>

void Init_game(MAP *M, Player *P1, Player *P2);
/* Function to setup kings, tower, castle, and villages before game starts */

void Show_title();
/* Function to show title, well ~ */

#endif
