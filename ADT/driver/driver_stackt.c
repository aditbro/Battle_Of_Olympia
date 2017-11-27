#include "../stackt.h"
#include <stdio.h>

int main() {
	Stack S,s;
	stack_infotype dummy;

	stack_CreateEmpty(&s);

	if (stack_IsEmpty(s)) {
		printf("stack empty\n");
	}

	for (int i = 1; i <= 100; i++) {
		stack_Push(&s, i);
	}

	if (stack_IsFull(s)) {
		printf("stack penuh\n");
	}

	stack_CreateEmpty(&S);
	stack_Push(&S, 5);
	stack_Push(&S, 4);
	stack_Push(&S, 3);
	stack_Push(&S, 2);
	stack_Pop(&S, &dummy);
	stack_PrintStack(S);
}