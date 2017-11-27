
/* Module to handle unit list */

#include "unitlist.h"
#include <stdio.h>

/****************** LIST INFO ******************/
int UnitList_empty(address L)
/* Check wether unit list is empty or not */
{
    return L == NULL;
}


address Alokasi_point(infotype X, int indeks)
    /* return Address of new alocated element */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));

    if (P != NULL){

        Index(P) = indeks + 1;
        Info(P) = X;
        Next(P) = NULL;
        return P;
    }
    else {
        return NULL;
    }
}


int UnitNbElmt(UnitList L)
    /* Element amount */
{
    if (!UnitList_empty(L)){
        return 1 + UnitNbElmt(Tail(L));
    }
    else{
        return 0;
    }
}

int Index_Max(UnitList L)
    /* Return max index used in list */
{
    if (UnitList_empty(L)){
        return -999;
    }

    else{

        int Prev_Max = Index_Max(Tail(L));

        if (Index(L) > Prev_Max){
            return Index(L);
        }

        else{
            return Prev_Max;
        }

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


void Delete_unit (UnitList *L, int Index)
/* Delete an element at index X */
{

    address Prec = NULL;
    address Current = *L;
    int found = 0;

    while((Current != NULL) && !found){

        if (Index(Current) == Index){
            found = 1;
        }

        else{

            Prec = Current;
            Current = Next(Current);
        }
    }

    if (found){

        if (Prec != NULL){
            Next(Prec) = Next(Current);
            free(Current);
        }
        else{
            *L = Next(Current);
            free(Current);
        }
    }
}

POINT get_unit_position(UnitList L, int Index){
    /* Function to return unit position stored in unitlist by indexing */

    if (UnitList_empty(L)){
        return MakePOINT(-999,-999);
    }

    else if (Index(L) == Index){
        return Info(L);
    }

    else{
        return get_unit_position(Tail(L), Index);
    }
}


void select_unit(MAP *Map, UnitList Unit_list, UNIT * Current_unit, int Index){
    /* Change value of current unit by selecting unit in unitlist by index */

    POINT unit_pos = get_unit_position(Unit_list, Index);
    int i = Absis(unit_pos);
    int j = Ordinat(unit_pos);

    if ( (i >= 0) && (i <= MapBrsEff(*Map)) && (j >= 0) && (j <= MapKolEff(*Map))){
        *Current_unit = Unit(*Map,i,j);
        printf("current unit : unit < %.2d > \n", Index);
        selected_on_map_ON(Map, Current_unit, true);
    }
    else{
        printf("You don't have such unit...\n");
    }
}

void selected_on_map_ON(MAP *Map, UNIT *Current_unit, boolean Cond){
    /* Function to turn on and off 'select' atribut in map */

    Select(*Map, Absis(Pos(*Current_unit)), Ordinat(Pos(*Current_unit))) = Cond;
}


UnitList  change_unit_position_pre(UnitList Unit_list, UNIT *Current_unit, int *unit_index_in_list){
/* Function to delete unit in unitlist and store index */

    *unit_index_in_list = search_current_unit_index(Unit_list, Current_unit);

    /* If current unit is in list */
    if (unit_index_in_list != 0){
        Delete_unit(&Unit_list, *unit_index_in_list);
    }

    return Unit_list;
}


UnitList change_unit_position_post(UnitList Unit_list, UNIT *Current_unit, int unit_index_in_list) {
    /* Function to insert unit in unitlist after the position is modified */

    if (unit_index_in_list != 0){

        return Insert_unit(Unit_list, Pos(*Current_unit), unit_index_in_list-1);

    }
    else{

        return NULL;
    }
}

int search_current_unit_index(UnitList Unit_list, UNIT *Current_unit){
    /* Function to return index of current unit in unitlist */

    if (UnitList_empty(Unit_list)){
        return 0;
    }

    else{

        if (point_EQ(Info(Unit_list), Pos(*Current_unit))){
            return Index(Unit_list);
        }

        else{
            return search_current_unit_index(Tail(Unit_list), Current_unit);
        }
    }

}

int search_next_unit(MAP *M, UnitList Unit_list,UNIT *Current_unit){
    /* function to return next index of unit that can move / attack */

    int max_idx = Index_Max(Unit_list);
    int cur_idx = search_current_unit_index(Unit_list, Current_unit);
    int max_repeat = UnitNbElmt(Unit_list);

    /* Modular increment */
    while(max_repeat > 0){

        if (cur_idx == max_idx){
            cur_idx = 1;
        }
        else{
            cur_idx += 1;
        }

        POINT Unit_pos = get_unit_position(Unit_list, cur_idx);
        UNIT check_unit = Unit(*M, Absis(Unit_pos), Ordinat(Unit_pos));

        if ((Mov(check_unit) >= 0) || Can_Atk(check_unit)){
            return cur_idx;
        }

        max_repeat--;
    }

    return -999;
}

/****************** DISPLAY ******************/
void Display_unit_list (MAP M, UnitList L)
    /* Display unit index and unit position */
{
    if (!UnitList_empty(L)){

        POINT unit_pos = get_unit_position(L, Index(L));

        show_unit_in_list(Unit(M, Absis(unit_pos), Ordinat(unit_pos)), Index(L));
        printf("\n");
        Display_unit_list(M, Tail(L));
    }
}

void show_unit_in_list(UNIT U, int Index){
/* Function to show unit data */

    if (Type(U) != '0'){
        printf("%d. ",Index);
        print_unit_type(U);
        printf("  ");
        TulisPOINT(Pos(U));
        printf(" | ");
        printf("Health %d", Hp(U));
    }
}

void refresh_unit_list(MAP *M,UnitList L)
/* Refresh Can_Atk,Mov all Unit in UnitList*/
{
    if(!UnitList_empty(L)){
        POINT unit_pos = get_unit_position(L,Index(L));

        Can_Atk(Unit(*M, Absis(unit_pos), Ordinat(unit_pos)))=true;
        Mov(Unit(*M, Absis(unit_pos), Ordinat(unit_pos)))=M_Mov(Unit(*M, Absis(unit_pos), Ordinat(unit_pos)));
        refresh_unit_list(M,Tail(L));
        refreshMap(M,L);
    }
}

void do_heal(MAP *M,UnitList L)
/* Heal with your white mage */
{
    if(!UnitList_empty(L)){
        POINT unit_pos = get_unit_position(L,Index(L));

        if(Type(Unit(*M, Absis(unit_pos), Ordinat(unit_pos)))=='W'){
            heal(Unit(*M, Absis(unit_pos), Ordinat(unit_pos)),M);
        }

        do_heal(M,Tail(L));
    }
}

void refreshMap(MAP *M,UnitList L)
/* Refresh Can_Atk,Mov all Unit in UnitList*/
{
    if(!UnitList_empty(L)){
        POINT unit_pos = get_unit_position(L,Index(L));

        selected_on_map_ON(M, &Unit(*M,Absis(unit_pos), Ordinat(unit_pos)), false);
        refreshMap(M,Tail(L));
    }
}
