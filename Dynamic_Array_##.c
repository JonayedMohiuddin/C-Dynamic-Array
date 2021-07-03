#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *array;
	size_t used; // size_t is just a alias of unsigned int. It is typedef'd in stdlib.h library.
	size_t size; // size_t ~ unsigned int
} Array;

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, int element);
void freeArray(Array *a);

int main()
{
	// Declaring dynamic array
	Array array;
	// Initializing array with 20 element capacity
	initArray(&array, 20);
	
	int i;
	for(i=1; i<=100; i++)
	{
		// Inserts value i*100 in array
		insertArray(&array, i*100);
	}
	
	// Though the array's capacity was 20 it can expand and allocate more elemnt than that.
	
	for(i=0; i<100; i++)
	{
		printf("%2d th elemnt of array: %d\n", i+1, array.array[i]);
	}
	
	return 0;
}

// Method for initializing dynamic array
void initArray(Array *a, size_t initialSize)
{
	a->array = malloc(sizeof(int) * initialSize);
	a->used = 0;
	a->size = initialSize;
}

// Inserts an element the given array
void insertArray(Array *a, int element)
{
	// If array reached it's maximum size then double the size. This method is efficient though it looks inefficient.
	if(a->used == a->size)
	{
		a->size *= 2;
		a->array = realloc(a->array, sizeof(int) * a->size);
	}
	
	a->array[a->used++] = element;
}

// Frees array after it's of no more use.
void freeArray(Array *a)
{
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}
