
#ifndef UNITBATTLE_H
#define UNITBATTLE_H

#include "ADT/point.h"
#include "ADT/boolean.h"

#include "unit.h"
#include "map.h"
#include "ADT/matriks.h"

boolean get_hit (UNIT Defender);
void unit_attack(UNIT * Attacker, UNIT * Defender);
/*I.S. Attacker dan Defender letaknya bersebalahan*/
/*F.S. health dari Attacker dan Defender berubah sesuai kondisi*/
void attack(UNIT *Attacker, MAP *M);
/*I.S. Attacker terdefinisi*/
/*F.S. menjalankan command attack sesuai kondisi yang terdefinisi*/

#endif