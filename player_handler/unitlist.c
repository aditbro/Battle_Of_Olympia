
/* Module to handle unit list */

#include "unitlist.h"

/* NOTES :
#define Unit_index(P) (P)->list_index
#define Unit_info(P) (P)->unit_info
#define Next(P) (P)->next

UnitList

*/

/****************** LIST INFO ******************/
int UnitList_empty (UnitList L)
/* Check wether unit list is empty or not */
{
    return Next(L) == Nil;
}

UnitList Create_new_unitlist()
{
    UnitList L;
    Unit_index(L) = -999;
    Unit_info(L) = Create_new_unit('D',0,0,0);
    Next(L) = Nil;

    return L;
}

/****************** ADD AND DEL ******************/
void Insert_unit (UnitList *L, UNIT unit)
/* Append an unit to list */
{
    UnitList New_element = Create_new_unitlist();

    int last_index = 0;
    address last = L;
    address Current = L;


    /* Search for last element */
    while(Next(Current) != Nil ){
        last = Current;
        last_index = Unit_index(Current);

        Current = Next(Current);
    }

    /* Insert */
    Next(last) = New_element;
    Unit_info(New_element) = unit;
    Unit_index(New_element) = last_index + 1 ;

}


void Delete_unit (UnitList *L, int Index)
/* Delete an element at index X */
{

    address last = L;
    address Current = L;
    boolean found = false;

    /* Search for last element */
    while((Current != Nil) && !found ){

        last = Current;

        if (Unit_index(Current) == Index){
            found = true;
        }
        else{
            Current = Next(Current);
        }
    }

    /* Delete it */
    if (found){
        Next(last) = Next(Current);
        free(Current);
    }
}

/****************** DISPLAY ******************/
void Display_unit_list (UnitList L){

    if (!UnitList_empty(L)){
        Show_unit_info(Unit_info(L));
        Display_unit_list(Next(L));
    }
    else{
        Show_unit_info(Unit_info(L));
    }
}


/****************** DESTRUCT ******************/
void Destruct_unit_list (UnitList *L)
/* Delete all */
{
    if (!UnitList_empty(*L)){
        Destruct_unit_list(Next(*L));
        free(*L);
    }
    else{
        free(*L);
    }
}
