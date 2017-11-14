
/* Module to handle unit list */

#ifndef unitlist_H
#define unitlist_H

#include "../unit.h"
#include "../ADT/point.h"
#include <stdlib.h>

#define Nil NULL

typedef POINT infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    int index;
	infotype info;
	address next;
} ElmtList;

typedef address UnitList;

#define Index(P) (P)->index
#define Info(P) (P)->info
#define Next(P) (P)->next

/* NOTES :
    - Start off :
        UnitList UNITLIST = NULL;
    - Usage :
        UNITLIST = Insert_unit(UNITLIST, point, NbElmt(UNITLIST));
        Delete_unit(UNITLIST, 3);
        Display_unit_list(UNITLIST);

*/


/****************** ADD AND DEL ******************/
UnitList Insert_unit(UnitList L, POINT unit_pos, int indeks);
/* Insert a element into list */

void Delete_unit (UnitList L, int Index);
/* Delete an element at index X */


/****************** DISPLAY ******************/
void Display_unit_list (UnitList L);
/* Display unit index and unit position */


/****************** SHOULD NOT BE USED DIRECTLY ******************/
int UnitList_empty(address L);

address Alokasi_point(infotype X, int indeks);

int NbElmt(UnitList L);

UnitList Tail(UnitList L);

#endif
