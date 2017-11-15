#include "map.h"
#include "unit.h"
#include "building.h"
#include "info.h"

Build SearchTower (MAP M, UNIT K);
/* Mencari letak tower milik pemain */

boolean IsCastleEmpty (MAP M, int x, int y);
/* Mengecek apakah castle yang dipilih kosong */

boolean castle_available (MAP M, Build T);
/* Mengecek apakah ada castle yang kosong (untuk validasi) */

void recruit_unit (MAP M, UNIT K, UNIT *U);
/* Dipanggil di program utama saat user menginput command RECRUIT */

