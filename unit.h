
#ifndef UNIT_H
#define UNIT_H

#include "ADT/point.h"
#include "ADT/boolean.h"
#include "map.h"

typedef struct {
    char type;
    int max_health;
    int health;
    int attack;
    int max_movement;
    int movement;
    int cost;
    POINT position;
    char atk_type;
    boolean can_attack;

} UNIT;

#define Type(U) (U).type
#define M_Hp(U) (U).max_health
#define Hp(U) ((U).health)
#define Atk(U) (U).attack
#define M_Mov(U) (U).max_movement
#define Mov(U) (U).movement
#define Cost(U) (U).cost
#define Pos(U) (U).position
#define Atk_Type(U) (U).atk_type
#define Can_Atk(U) (U).can_attack



void Init_unit (UNIT * U);

UNIT Create_new_unit();

void Show_unit_info (UNIT U);

void attack(UNIT *Attacker);
/*I.S. Attacker terdefinisi*/
/*F.S. menjalankan command attack sesuai kondisi yang terdefinisi*/

void unit_attack(UNIT *Attacker, UNIT *Defender);
/*I.S. Attacker dan Defender letaknya bersebalahan*/
/*F.S. health dari Attacker dan Defender berubah sesuai kondisi*/


#endif
