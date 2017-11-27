#include "../mesinkata.h"
#include <stdio.h>

int main() {
	STARTKATA();

	while (!EndKata) {
		for (int i = 1; i <= CKata.Length; i++) {
			printf("%c", CKata.TabKata[i]);
		}
		printf(" ");
		ADVKATA();
	}

	return 0;
}