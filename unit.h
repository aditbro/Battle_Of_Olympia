
#ifndef UNIT_H
#define UNIT_H

#include "point.h"
#include "boolean.h"

typedef struct {

    int max_health;
    int health;
    int attack;
    int max_movement;
    int movement;
    int cost;
    POINT position;
    char type;
    boolean can_attack;

} UNIT;

#define M_Hp(U) (U).max_health
#define Hp(U) ((U).health)
#define Atk(U) (U).attack
#define M_Mov(U) (U).max_movement
#define Mov(U) (U).movement
#define Cost(U) (U).cost
#define Pos(U) (U).position
#define Type(U) (U).type
#define Can_Atk(U) (U).can_attack



void Init_unit (UNIT * U);

UNIT Create_new_unit();

void Show_unit_info (UNIT U);


#endif
