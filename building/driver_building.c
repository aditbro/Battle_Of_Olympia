#include "building.h"

int main() {
	Build C = create_new_build('C', 1, 4, 5);
	Build T = create_new_build('T', 1, 4, 5);
	Build V = create_new_build('V', 1, 4, 5);

	print_build_type(C); printf(", ");
	print_build_type(T); printf(", ");
	print_build_type(V); printf("\n");
}