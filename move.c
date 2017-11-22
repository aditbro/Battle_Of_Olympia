#include "map.h"
#include "unit.h"
#include <stdlib.h>
#include <stdio.h>
#include "ADT/stackt.h"
#include "ADT/point.h"

Stack X,Y,C;


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
	stack_CreateEmpty(&C);
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
    int i;

	POINT Loc = Pos(U);
	for( i = 1; i <= M_Mov(U) && Loc.X + i <= MapKolEff(*P); i++){
		if(Type(Unit(*P,Loc.X + i,Loc.Y)) == '0'){
			Type(Unit(*P,Loc.X + i,Loc.Y)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.X+i,Loc.Y))){
			break;
		}
	}
	for( i = 1; i <= M_Mov(U) && Loc.X - i >= 0; i++){
		if(Type(Unit(*P,Loc.X - i,Loc.Y)) == '0'){
			Type(Unit(*P,Loc.X - i,Loc.Y)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.X-i,Loc.Y))){
			break;
		}
	}
	for( i = 1; i <= M_Mov(U) && Loc.Y - i >= 0; i++){
		if(Type(Unit(*P,Loc.X,Loc.Y - i)) == '0'){
			Type(Unit(*P,Loc.X,Loc.Y - i)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.X,Loc.Y-i))){
			break;
		}
	}
	for( i = 1; i <= M_Mov(U) && Loc.Y + i <= MapBrsEff(*P); i++){
		if(Type(Unit(*P,Loc.X,Loc.Y + i)) == '0'){
			Type(Unit(*P,Loc.X,Loc.Y + i)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.X,Loc.Y+i))){
			break;
		}
	}
	for( i = 1; i <= M_Mov(U)/2 && Loc.Y + i <= MapBrsEff(*P) && Loc.X + i <= MapBrsEff(*P); i++){
		if(Type(Unit(*P,Loc.X + i,Loc.Y + i)) == '0'){
			Type(Unit(*P,Loc.X + i,Loc.Y + i)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.X + i,Loc.Y+i))){
			break;
		}			
	}
	for( i = 1; i <= M_Mov(U)/2 && Loc.Y - i >= 0 && Loc.X + i <= MapBrsEff(*P); i++){
		if(Type(Unit(*P,Loc.X + i,Loc.Y - i)) == '0'){
			Type(Unit(*P,Loc.X + i,Loc.Y - i)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.X + i,Loc.Y-i))){
			break;
		}			
	}
	for( i = 1; i <= M_Mov(U)/2 && Loc.Y + i <= MapBrsEff(*P) && Loc.X - i >= 0; i++){
		if(Type(Unit(*P,Loc.X - i,Loc.Y + i)) == '0'){
			Type(Unit(*P,Loc.X - i,Loc.Y + i)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.X-i,Loc.Y+i))){
			break;
		}			
	}
	for( i = 1; i <= M_Mov(U)/2 && Loc.Y - i >= 0 && Loc.X - i >= 0;i++){
		if(Type(Unit(*P,Loc.X - i,Loc.Y - i)) == '0'){
			Type(Unit(*P,Loc.X - i,Loc.Y - i)) = '#';
		}
		else if(Owner(U) != Owner(Unit(*P,Loc.X - i,Loc.Y-i))){
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
	if(Unit(temp, x, y).type != '#'){
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
	Unit(*P, Loc.X,Loc.Y).type = '0';
	Unit(*P, Loc.X,Loc.Y).owner = 0;
	stack_Push(&X, Loc.X);
	stack_Push(&Y, Loc.Y);
	int x1 = Loc.X;
	int y1 = Loc.Y;
	Loc.X = x;
	Loc.Y = y;
	Unit(*P,x,y) = *U;
	Pos(*U) = Loc;
	if(Build(*P, x, y).type == 'V'){
		M_Mov(*U) = 0;
		stack_Push(&C, Build(*P,x,y).owner);
		Build(*P,x,y).owner = Owner(*U);
	}else{
		if(x1 - x == 0 || y - y1 == 0){
			M_Mov(*U) -= absolute((x1-x)+(y1-y));
		else{
			M_Mov(*U) -= absolute((x1-x));
		}
void undo(MAP *P, UNIT *U)
/*prosedur ini mengembalikan state unit ke state sebelum pindah */
{
	if(stack_IsEmpty(Y) || stack_IsEmpty(X)){
		printf("there's no move to undo\n");
		return;
	}
	int xs;
	stack_Pop(&X, &xs);
	int ys;
	stack_Pop(&Y, &ys);
	POINT Loc = Pos(*U);
	Unit(*P, Loc.X,Loc.Y).type = '0';
	Unit(*P, Loc.X,Loc.Y).owner = 0;
	if(Build(*P, Loc.X, Loc.Y).type == 'V'){
		int conquered = 0;
		stack_Pop(&C, &conquered);
		Build(*P, Loc.X, Loc.Y).owner = conquered;
	}
	Loc.X = xs;
	Loc.Y = ys;
	Unit(*P,xs,ys) = *U;
	Pos(*U) = Loc;
	M_Mov(*U) += 1;
}