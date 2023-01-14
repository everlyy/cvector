#include <stdio.h>

#define VECTOR_TYPE everly_uint
#define VECTOR_FMT "%d"
#include "vector.h"

#undef VECTOR_TYPE
#define VECTOR_TYPE float
#undef VECTOR_FMT
#define VECTOR_FMT "%.1f"
#include "vector.h"

int main(void) {
	vector_int_t vector1;
	vector_int_init(&vector1);

	vector_int_append(&vector1, 1);
	vector_int_append(&vector1, 2);
	vector_int_append(&vector1, 4);
	vector_int_append(&vector1, 5);
	vector_int_insert(&vector1, 2, 3);
	vector_int_print(&vector1);

	printf("\n");

	vector_float_t vector2;
	vector_float_init(&vector2);

	vector_float_append(&vector2, 1.1);
	vector_float_append(&vector2, 2.2);
	vector_float_append(&vector2, 4.4);
	vector_float_append(&vector2, 5.5);
	vector_float_insert(&vector2, 2, 3.3);
	vector_float_print(&vector2);

	return 0;
}