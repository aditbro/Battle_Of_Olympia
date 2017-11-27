#include "../matriks.h"
#include <stdio.h>

int main() {
	MATRIKS M;
	int row = 10;
	int col = 10;
	
	if (matriks_IsIdxValid(row, col)) {
		matriks_MakeMATRIKS(10, 10, &M);
		printf("Matriks telah dibuat.");
	}
	else {
		printf("Matriks gagal dibuat. Indeks tidak valid");
	}

}