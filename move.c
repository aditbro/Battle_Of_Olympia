#include "map.h"
#include "unit.h"
#include <stdlib.h>
#include <stdio.h>
#include "ADT/stackt.h"
#include "ADT/point.h"

Stack X,Y;


int absolute(int x){
	if(x < 0){
		return -x;
	}else{
		return x;
	}
}

void call_move(MAP P, UNIT U)
/*prosedur ini berguna ketika player memilih untuk change unit dan di awal turn
 * walaupun player tidak akan menggunakan move
 *
 * prosedur ini akan menginisialisasi STACK sehingga bisa melakukan UNDO
 */
{
	stack_CreateEmpty(&S);
}

void print_possible_move(MAP P,UNIT U)
/**prosedur ini menampilkan map yang sudah berisi
 * semua langkah-langkah yang mungkin
 * dilakukan oleh sebuah unit
 *
 * diasumsikan pada awalnya di setiap lokasi peta diinisialisasi unit bernilai U
 */
{
	POINT Loc = Pos(U);
	for(int i = 1; i <= M_mov(U); i++){
		if(Type(Unit(P,Loc.Y + i,Loc.X)) == 'U'){
			Type(Unit(P,Loc.Y + i,Loc.X)) = '#';
		}
	}
	for(int i = 1; i <= M_mov(U); i++){
		if(Type(Unit(P,Loc.Y - i,Loc.X)) == 'U'){
			Type(Unit(P,Loc.Y - i,Loc.X)) = '#';
		}
	}
	for(int i = 1; i <= M_mov(U); i++){
		if(Type(Unit(P,Loc.Y,Loc.X - i)) == 'U'){
			Type(Unit(P,Loc.Y - i,Loc.X - i)) = '#';
		}
	}
	for(int i = 1; i <= M_mov(U); i++){
		if(Type(Unit(P,Loc.Y,Loc.X + i)) == 'U'){
			Type(Unit(P,Loc.Y,Loc.X + i)) = '#';
		}
	}
	printMap(P);
}

int check_if_possible(MAP P, UNIT U, int x, int y)
/*fungsi ini memeriksa apakah sebuah unit bisa pindah ke suatu
 * koordinat atau tidak, apabila bisa, maka fungsi akan mengembalikan true/1
 * jika tidak, fungsi akan mengembalikan false/0
 */
{
	POINT Loc = Pos(U);
	int distance = x-Loc.X + y - Loc.Y;
	if(Type(Unit(P,y,x)) != 'U'){
		return 0;
	}else if(absolute(distance) > M_mov(U)){
		return 0;
	}else{
		return 1;
	}
}
void move_unit(MAP P, UNIT *U, int x, int y)
/*prosedur ini akan memindahkan unit menuju sebuah sel yang berkoordinat (x,y)
 * lalu memasukan lokasi sebelumnya ke stack agar bisa melakukan undo
 */
{
	POINT Loc = Pos(*U);
	stack_push(&X, Loc.X);
	stack_push(&Y, Loc.Y);
	Loc.X = x;
	Loc.Y = y;
	Pos(*U) = Loc;
	M_mov(*U) -= 1;
}
void undo(MAP P, UNIT *U)
/*prosedur ini mengembalikan state unit ke state sebelum pindah */
{
	int xs;
	stack_pop(&X, &xs);
	int ys;
	stack_pop(&Y, &ys);
	move_unit(P, U, xs, ys);
	M_mov(*U) += 2;
}
