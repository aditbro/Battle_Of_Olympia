/**Header untuk fungsi-fungsi move**/

#ifndef MOVE_H
#define MOVE_H

#include "map.h"
#include "unit.h"
#include <stdlib.h>
#include <stdio.h>
#include "ADT/stackt.h"

Stack S;

void call_move(MAP P, UNIT U);
/*prosedur ini berguna ketika player memilih untuk change unit dan di awal turn
 * walaupun player tidak akan menggunakan move
 *
 * prosedur ini akan menginisialisasi STACK sehingga bisa melakukan UNDO
 */

void print_possible_move(MAP P,UNIT U);
/**prosedur ini menampilkan map yang sudah berisi
 * semua langkah-langkah yang mungkin
 * dilakukan oleh semua unit
 */

int check_if_possible(MAP P, UNIT U, int x, int y);
/*fungsi ini memeriksa apakah sebuah unit bisa pindah ke suatu
 * koordinat atau tidak, apabila bisa, maka fungsi akan mengembalikan true/1
 * jika tidak, fungsi akan mengembalikan false/0
 */

void move_unit(MAP P, UNIT U, int x, int y);
/*prosedur ini akan memindahkan unit menuju sebuah sel yang berkoordinat (x,y)
 * lalu memasukan lokasi sebelumnya ke stack agar bisa melakukan undo
 */

void undo(MAP P, UNIT U);
/*prosedur ini mengembalikan state unit ke state sebelum pindah */


#endif
