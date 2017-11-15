
/* Module to handle unit list */

#ifndef unitlist_H
#define unitlist_H

#include "../unit.h"
#include "../map.h"
#include "../ADT/point.h"
#include <stdlib.h>

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

    - Testing program :

    int main (void){
        POINT point;
        UnitList UNITLIST = NULL;
        UNIT Current_unit;

        point = Pos(Unit(M, 1, 1));
        printf("\nInserting unit1\n");
        UNITLIST = Insert_unit(UNITLIST, point, NbElmt(UNITLIST));

        point = Pos(Unit(M, 1, 2));
        printf("\nInserting unit2\n");
        UNITLIST = Insert_unit(UNITLIST, point, NbElmt(UNITLIST));

        printf("\nDisplaying unit\n");
        Display_unit_list(M, UNITLIST);

        printf("\nShow current unit (unit 1) info...\n");
        select_unit(M, UNITLIST, &Current_unit, 1);
        Show_unit_info(Current_unit);

        printf("\nChange unit...");
        printf("\nShow current unit (unit 2) info...\n");
        select_unit(M, UNITLIST, &Current_unit, 2);
        Show_unit_info(Current_unit);

        return 0;
    }
*/


/****************** ADD AND DEL ******************/
UnitList Insert_unit(UnitList L, POINT unit_pos, int indeks);
/* Insert a element into list */

void Delete_unit (UnitList L, int Index);
/* Delete an element at index X */

POINT get_unit_position(UnitList L, int Index);

void select_unit(MAP Map, UnitList Unit_list, UNIT * Current_unit, int Index);
/****************** DISPLAY ******************/
void Display_unit_list (MAP M, UnitList L);
/* Display unit index and unit position */

void show_unit_in_list(UNIT U);
/* Function to show unit data  */

/****************** SHOULD NOT BE USED DIRECTLY ******************/
int UnitList_empty(address L);

address Alokasi_point(infotype X, int indeks);

int NbElmt(UnitList L);

UnitList Tail(UnitList L);

#endif
