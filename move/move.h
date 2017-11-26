#include "map.h"
#include "unit.h"
#include <stdlib.h>
#include <stdio.h>
#include "ADT/stackt.h"
#include "ADT/point.h"

Stack X,Y;

void call_move();
/*prosedur ini berguna ketika player memilih untuk change unit dan di awal turn
 * walaupun player tidak akan menggunakan move
 *
 * prosedur ini akan menginisialisasi STACK sehingga bisa melakukan UNDO
 */

void change_unit(MAP P, UNIT New, UNIT *U);
/*prosedur ini berguna untuk memilih unit yang akan dipindahkan*/

void possible_move(MAP *P,UNIT U);
/*prosedur ini mengubah map menjadi map yang sudah berisi
 * semua langkah-langkah yang mungkin
 * dilakukan oleh sebuah unit
 *
 * diasumsikan pada awalnya di setiap lokasi peta diinisialisasi unit bernilai '0'
 */


void print_possible_move(MAP P, UNIT U);
/*print semua possible move dari suatu unit*/

int check_if_possible(MAP P, UNIT U, int x, int y);
/*fungsi ini memeriksa apakah sebuah unit bisa pindah ke suatu
 * koordinat atau tidak, apabila bisa, maka fungsi akan mengembalikan true/1
 * jika tidak, fungsi akan mengembalikan false/0
 */

void move_unit(Player *p1, Player *p2,MAP *P, UNIT *U, int x, int y);
/*prosedur ini akan memindahkan unit menuju sebuah sel yang berkoordinat (x,y)
 * lalu memasukan lokasi sebelumnya ke stack agar bisa melakukan undo
 */

void undo(Player *p1, Player *p2,MAP *P, UNIT *U);
/*prosedur ini mengembalikan state unit ke state sebelum pindah */
