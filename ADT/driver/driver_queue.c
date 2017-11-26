#include "../queue.h"
#include <stdio.h>

int main() {
	Queue Q;
	queue_infotype q;

	queue_CreateEmpty(&Q,20);
	if (queue_IsEmpty(Q)) {
		printf("Queue is empty \n");
	}

	queue_Add(&Q, 1);
	queue_Add(&Q, 2);
	queue_Add(&Q, 3);

	while (!queue_IsEmpty(Q)) {
		printf("Jumlah El Q : %d\n", queue_NBElmt(Q));
		queue_Del(&Q, &q);
		printf("%d keluar\n", q);
	}
	printf("Queue is empty now\n");
}