#ifndef RECRUIT_H
#define RECRUIT_H

#include "../player/player.h"
#include "../map/map.h"
#include "../unit/unit.h"
#include "../building/building.h"
#include "../info/info.h"

Build SearchTower (MAP M, Player P);
/* Mencari letak tower milik pemain */

boolean IsCastleEmpty (MAP M, int x, int y);
/* Mengecek apakah castle yang dipilih kosong */

boolean castle_available (MAP M, Build T);
/* Mengecek apakah ada castle yang kosong (untuk validasi) */

void recruit_unit(MAP *M, Player *P, UNIT K);
/* Dipanggil di program utama saat user menginput command RECRUIT */

#endif
