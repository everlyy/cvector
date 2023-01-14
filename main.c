#include <stdio.h>

#define VECTOR_TYPE int
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

	printf("\n");

	vector_int_t vector3;
	vector_int_init(&vector3);

	for(size_t i = 0; i < 8; i++)
		vector_int_append(&vector3, i);

	vector_int_remove_at(&vector3, 3);
	vector_int_insert(&vector3, 6, 100);
	vector_int_print(&vector3);

	return 0;
}