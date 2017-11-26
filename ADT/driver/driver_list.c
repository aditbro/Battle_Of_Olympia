#include "../listlinier.h"
#include <stdio.h>

int main() {
	List L;

	list_CreateEmpty(&L);
	list_InsVLast(&L, 1);
	list_InsVLast(&L, 2);
	list_InsVLast(&L, 3);

	printf("Jumlah element : %d\n", list_NbElmt(L));
	list_PrintInfo(L);
	printf("\n");
}