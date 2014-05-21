#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

struct structA {
	int f1;
	char f2;
	float f3;
};

struct structB {
	int f1;
	struct structA f2;
	struct structA *f3;
};

int main(int argc, char *argv[]) {
	struct structA a1 = {
		.f1 = 15,
		.f2 = 'A',
		.f3 = 3.1415926,
	};
	struct structB b1 = {
		.f1 = 0,
		.f2 = {
			.f1 = 8,
			.f2 = 'B',
			.f3 = 2.71828,
		},
		.f3 = &a1,
	}; 
	
	float c1 = 3.1415926;

	memdump("a1 = ", &a1, sizeof(a1));
	structdump(&a1, a1, 3, f1, f2, f3);

	memdump("b1 = ", &b1, sizeof(b1));
	structdump(&b1, b1, 3, f1, f2, f3);

	memdump("c1 = ", &c1, sizeof(c1));

	exit(0);
}
