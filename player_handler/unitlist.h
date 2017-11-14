
/* Module to handle unit list */

#ifndef unitlist_H
#define unitlist_H

#include "../unit.h"
#include <stdlib.h>
#include "../ADT/listlinier.h"


#define Unit_index(P) (P)->list_index
#define Unit_info(P) (P)->unit_info
#define Next(P) (P)->next

/****************** LIST INFO ******************/
int UnitList_empty (UnitList L);
/* Check wether unit list is empty or not */

UnitList Create_new_unitlist();
/* Create Empty list */

/****************** ADD AND DEL ******************/
void Insert_unit (UnitList *L, UNIT unit);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void Delete_unit (UnitList *L, int Index);
/* Delete an element at index X */

/****************** DISPLAY ******************/
void Display_unit_list (UnitList L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

/****************** DESTRUCT ******************/
void Destruct_unit_list (UnitList *L);
/* Delete semua elemen list dan alamat elemen di-dealokasi */

#endif
