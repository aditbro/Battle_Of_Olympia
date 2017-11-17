#ifndef RECRUIT_H
#define RECRUIT_H

#include "player_handler/player.h"
#include "map.h"
#include "unit.h"
#include "building.h"
#include "info.h"

Build SearchTower (MAP M, Player P);
/* Mencari letak tower milik pemain */

boolean IsCastleEmpty (MAP M, int x, int y);
/* Mengecek apakah castle yang dipilih kosong */

boolean castle_available (MAP M, Build T);
/* Mengecek apakah ada castle yang kosong (untuk validasi) */

void recruit_unit (MAP M, Player *P, UNIT K, UNIT *U);
/* Dipanggil di program utama saat user menginput command RECRUIT */

#endif