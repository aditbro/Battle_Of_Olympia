
#ifndef UNIT_H
#define UNIT_H

#include "ADT/point.h"
#include "ADT/boolean.h"
#include "ADT/matriks.h"

typedef struct {
    char type;
    int owner;
    int max_health;
    int health;
    int attack;
    int defence;
    int heal;
    int max_movement;
    int movement;
    int cost;
    POINT position;
    char atk_type;
    boolean can_attack;
    int get_hit_probability; // probabilitas kena serangan, 100 untuk selalu kena serangan, 0 tidak pernah bisa kena serangan
} UNIT;

#define Type(U) (U).type
#define Owner(U) (U).owner
#define M_Hp(U) (U).max_health
#define Hp(U) ((U).health)
#define Atk(U) (U).attack
#define Def(U) (U).defence
#define Heal(U) (U).heal
#define M_Mov(U) (U).max_movement
#define Mov(U) (U).movement
#define Cost(U) (U).cost
#define Pos(U) (U).position
#define Atk_Type(U) (U).atk_type
#define Can_Atk(U) (U).can_attack
#define GHP(U) (U).get_hit_probability

void Init_unit(UNIT * U,char type,int owner,int x, int y);
UNIT Create_new_unit(char type,int owner,int x, int y);
void print_unit_type(UNIT U);
/*I.S. U terdefinisi*/
/*F.S. menuliskan jenis dari U*/

void Show_unit_info (UNIT U);

void show_unit_available(UNIT U,boolean Retaliates);
/*I.S. U terdefinisi*/
/*F.S. menuliskan atribut dari unit yang available*/

#endif
