#ifndef VECTOR_CAT
#define _VECTOR_CAT(a, b) a##b
#define VECTOR_CAT(a, b) _VECTOR_CAT(a, b)
#endif // VECTOR_CAT

#ifndef VECTOR_TYPE
#error "VECTOR_TYPE is not defined."
#endif

#ifndef VECTOR_FMT
#warning "VECTOR_FMT is not defined. Vector printing won't be available."
#endif

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// Function names are: vector_TYPE_FUNC
// so the init function of an int vector would be: vector_int_init
#define VECTOR_FUNCTION(name) VECTOR_CAT(vector_, VECTOR_CAT(VECTOR_TYPE, VECTOR_CAT(_, name)))

// Vector struct name is: vector_TYPE_t
// so the struct of an int vector would be: vector_int_t 
#define STRUCT_NAME VECTOR_CAT(vector_, VECTOR_CAT(VECTOR_TYPE, _t))

#define STARTING_CAPACITY 8

typedef struct {
	size_t length;		// Actual number of elements in vector
	size_t capacity;	// Number of elements that could fit.
	VECTOR_TYPE* elements;
} STRUCT_NAME;

static void VECTOR_FUNCTION(increase_capacity)(STRUCT_NAME* vector) {
	size_t new_capacity = vector->capacity * 2;
	vector->elements = realloc(vector->elements, new_capacity);
	vector->capacity = new_capacity;
}

void VECTOR_FUNCTION(init)(STRUCT_NAME* vector) {
	assert(vector);

	vector->elements = malloc(STARTING_CAPACITY * sizeof(VECTOR_TYPE));
	vector->capacity = STARTING_CAPACITY;
	vector->length = 0;
}

void VECTOR_FUNCTION(insert)(STRUCT_NAME* vector, size_t index, VECTOR_TYPE value) {
	assert(vector);

	if(vector->length == vector->capacity)
		VECTOR_FUNCTION(increase_capacity)(vector);

	// Move elements to the right so the new value can be inserted
	memmove(&vector->elements[index + 1], &vector->elements[index], (vector->length - index) * sizeof(VECTOR_TYPE));

	vector->length++;
	vector->elements[index] = value;
}

void VECTOR_FUNCTION(remove_at)(STRUCT_NAME* vector, size_t index) {
	assert(vector);
	assert(index < vector->length);

	memmove(&vector->elements[index], &vector->elements[index + 1], (vector->length - index) * sizeof(VECTOR_TYPE));
	vector->length--;
}

VECTOR_TYPE VECTOR_FUNCTION(at)(STRUCT_NAME* vector, size_t index) {
	assert(vector);
	assert(index < vector->length);

	return vector->elements[index];
}

void VECTOR_FUNCTION(append)(STRUCT_NAME* vector, VECTOR_TYPE value) {
	assert(vector);

	if(vector->length == vector->capacity)
		VECTOR_FUNCTION(increase_capacity)(vector);

	vector->elements[vector->length++] = value;
}

VECTOR_TYPE VECTOR_FUNCTION(pop)(STRUCT_NAME* vector) {
	assert(vector);
	assert(vector->length > 0);

	return vector->elements[--vector->length];
}

#ifdef VECTOR_FMT
void VECTOR_FUNCTION(print)(STRUCT_NAME* vector) {
	assert(vector);

	for(size_t i = 0; i < vector->length; i++) {
		printf("[%ld] => "VECTOR_FMT"\n", i, vector->elements[i]);
	}
}
#endif // VECTOR_FMT