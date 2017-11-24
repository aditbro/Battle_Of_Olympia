
/* Module to handle village list */

#ifndef villagelist_H
#define villagelist_H

#include "../unit.h"
#include "../map.h"
#include "../ADT/point.h"
#include <stdlib.h>

typedef POINT infotype;
typedef struct tVillageElmtlist *village_address;
typedef struct tVillageElmtlist {
    int index;
	infotype info;
	village_address next;
} VillageElmtList;

typedef village_address VillageList;

#define Index(P) (P)->index
#define Info(P) (P)->info
#define Next(P) (P)->next


/****************** ADD AND DEL ******************/
VillageList Insert_village(VillageList L, POINT village_pos, int indeks);
/* Insert a element into list */

village_address Alokasi_village_point(infotype X, int indeks);
/* Function to alocate point to store village position */

void Delete_village (VillageList L, int Index);
/* Delete an element at index X */

POINT get_village_position(VillageList L, int Index);

/****************** DISPLAY ******************/
void Display_village_list (MAP M, VillageList L);
/* Display village index and village position */

void show_village_in_list(Build B);
/* Function to show village data  */

/****************** SHOULD NOT BE USED DIRECTLY ******************/
int VillageList_empty(village_address L);

int VillageNbElmt(VillageList L);

VillageList VillageTail(VillageList L);

#endif
