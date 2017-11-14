
/* Module to handle unit list */

#include "unitlist.h"
#include <stdio.h>

/****************** LIST INFO ******************/
int UnitList_empty(address L)
/* Check wether unit list is empty or not */
{
    return L == Nil;
}


address Alokasi_point(infotype X, int indeks)
    /* return Address of new alocated element */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));

    if (P != Nil){

        Index(P) = indeks + 1;
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}


int NbElmt(UnitList L)
    /* Element amount */
{
    if (!UnitList_empty(L)){
        return 1 + NbElmt(Tail(L));
    }
    else{
        return 0;
    }
}


UnitList Tail(UnitList L)
{
    return Next(L);
}

/****************** ADD AND DEL ******************/
UnitList Insert_unit(UnitList L, POINT unit_pos, int indeks)
/* Insert a element into list */
{
    if (UnitList_empty(L)){
        return Alokasi_point(unit_pos, indeks);
    }

    else{
        Next(L) = Insert_unit(Tail(L), unit_pos, indeks);
        return L;
    }
}


void Delete_unit (UnitList L, int Index)
/* Delete an element at index X */
{

    address Prec = Nil;
    address Current = L;
    int found = 0;

    while((Current != Nil) && !found){

        if (Index(Current) == Index){
            found = 1;
        }

        else{

            Prec = Current;
            Current = Next(Current);
        }
    }

    if (found){

        Next(Prec) = Next(Current);
        free(Current);
    }
}

/****************** DISPLAY ******************/
void Display_unit_list (UnitList L)
    /* Display unit index and unit position */
{
    if (!UnitList_empty(L)){

        printf("Hero : %d >> ",Index(L));
        TulisPOINT(Info(L));
        printf("\n");
        Display_unit_list(Tail(L));
    }
}
