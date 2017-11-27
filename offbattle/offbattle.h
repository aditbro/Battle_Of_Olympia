
#ifndef OFFBATTLE_H
#define OFFBATTLE_H

#include "../ADT/matriks.h"
#include "../ADT/point.h"

#include "../building/building.h"
#include "../map/map.h"
#include "../unit/unit.h"
#include "../unitlist/unitlist.h"
#include "../player/player.h"

#include <stdlib.h>
#include <time.h>

void Init_game(MAP *M, Player *P1, Player *P2);
/* Function to setup kings, tower, castle, and villages before game starts */

void Show_title();
/* Function to show title, well ~ */

void Show_win();
/* Function to show win notification */

void Show_lose();
/* Function to show lose notification */

#endif
