#include "../point.h"
#include <stdio.h>

int main() {
	POINT P,P1;

	printf("point 1 :");
	BacaPOINT(&P);

	printf("point 2 :");
	BacaPOINT(&P1);

	TulisPOINT(P);
	TulisPOINT(P1);

	if (IsOrigin(P)) {
		printf("P titik origin\n");
	}

	if (IsOnSbX(P)) {
		printf("P terletak pada sumbu x\n");
	}

	if (IsOnSbY(P)) {
		printf("P terletak pada sumbu y\n");
	}

	if (point_EQ(P, P1)) {
		printf("P = P1\n");
	}

	if (NEQ(P, P1)) {
		printf("P = P1\n");
	}

	P1 = NextX(P);
	printf("absis P + 1 : "); TulisPOINT(P1);
	printf("\n");

	P1 = NextY(P);
	printf("absis P + 1 : "); TulisPOINT(P1);
	printf("\n");

	P1 = PlusDelta(P,2,3);
	printf("P + (2,3) : "); TulisPOINT(P1);
	printf("\n");

	Geser(&P, 2, 3);
	printf("P digeser (2,3) : "); TulisPOINT(P);
	printf("\n");

	GeserKeSbX(&P);
	printf("P digeser ke sb X : "); TulisPOINT(P);
	printf("\n");

	GeserKeSbY(&P);
	printf("P digeser ke sb Y : "); TulisPOINT(P);
	printf("\n");
}