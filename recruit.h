#include "map.h"
#include "unit.h"
#include "building.h"
#include "info.h"

Build SearchTower (Map M, Unit K);
// Mencari letak tower milik pemain

void IsCastleEmpty (Map M, int x, int y);
// Mengecek apakah castle yang dipilih kosong

boolean castle_available (Map M, Build T);
// Mengecek apakah ada castle yang kosong (untuk validasi)

void recruit_unit (Map M, Unit K, Unit *U);
// Dipanggil di program utama saat user menginput command RECRUIT