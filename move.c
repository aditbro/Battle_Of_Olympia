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

void call_move()
/*prosedur ini berguna ketika player memilih untuk change unit dan di awal turn
 * walaupun player tidak akan menggunakan move
 *
 * prosedur ini akan menginisialisasi STACK sehingga bisa melakukan UNDO
 */
{
	stack_CreateEmpty(&X);
	stack_CreateEmpty(&Y);
}

void change_unit(UNIT New, UNIT *U)
/*prosedur ini berguna untuk memilih unit yang akan dipindahkan*/
{
	*U = New;
	call_move();
}

void possible_move(MAP *P,UNIT U)
/**prosedur ini mengubah map menjadi map yang sudah berisi
 * semua langkah-langkah yang mungkin
 * dilakukan oleh sebuah unit
 *
 * diasumsikan pada awalnya di setiap lokasi peta diinisialisasi unit bernilai '0'
 */
{
	POINT Loc = Pos(U);
	for(int i = 1; i <= M_Mov(U); i++){
		if(Type(Unit(*P,Loc.Y + i,Loc.X)) == '0'){
			Type(Unit(*P,Loc.Y + i,Loc.X)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.Y+i,Loc.X))){
			break;
		}
	}
	for(int i = 1; i <= M_Mov(U); i++){
		if(Type(Unit(*P,Loc.Y - i,Loc.X)) == '0'){
			Type(Unit(*P,Loc.Y - i,Loc.X)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.Y-i,Loc.X))){
			break;
		}
	}
	for(int i = 1; i <= M_Mov(U); i++){
		if(Type(Unit(*P,Loc.Y,Loc.X - i)) == '0'){
			Type(Unit(*P,Loc.Y,Loc.X - i)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.Y,Loc.X-i))){
			break;
		}
	}
	for(int i = 1; i <= M_Mov(U); i++){
		if(Type(Unit(*P,Loc.Y,Loc.X + i)) == '0'){
			Type(Unit(*P,Loc.Y,Loc.X + i)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.Y,Loc.X+i))){
			break;
		}
	}
	//printMap(P);
}

void print_possible_move(MAP P, UNIT U)
/*print semua possible move dari suatu unit*/
{
	MAP temp = P;
	possible_move(&temp, U);
	printMap(temp);
}

int check_if_possible(MAP P, UNIT U, int x, int y)
/*fungsi ini memeriksa apakah sebuah unit bisa pindah ke suatu
 * koordinat atau tidak, apabila bisa, maka fungsi akan mengembalikan true/1
 * jika tidak, fungsi akan mengembalikan false/0
 */
{
	MAP temp = P;
	possible_move(&temp, U);
	if(Unit(temp, y, x).type != '#'){
		return 0;
	}else{
		return 1;
	}
}

void move_unit(MAP *P, UNIT *U, int x, int y)
/*prosedur ini akan memindahkan unit menuju sebuah sel yang berkoordinat (x,y)
 * lalu memasukan lokasi sebelumnya ke stack agar bisa melakukan undo
 */
{
	POINT Loc = Pos(*U);
	Unit(*P, Loc.Y,Loc.X).type = '0';
	stack_Push(&X, Loc.X);
	stack_Push(&Y, Loc.Y);
	Loc.X = x;
	Loc.Y = y;
	Unit(*P, Loc.Y,Loc.X) = *U;
	Pos(*U) = Loc;
	M_Mov(*U) -= 1;
}

void undo(MAP *P, UNIT *U)
/*prosedur ini mengembalikan state unit ke state sebelum pindah */
{
	int xs;
	stack_Pop(&X, &xs);
	int ys;
	stack_Pop(&Y, &ys);
	move_unit(P, U, xs, ys);
	M_Mov(*U) += 2;
}
