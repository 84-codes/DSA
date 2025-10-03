#ifndef dynArray
#define TYPE int
#define EQ(a, b) (a == b)

struct dynArr
{
    TYPE *data;
    int size;
    int capacity;
};
/* initialize a dynamic array structure with given capacity */
void dynArrayInit(struct dynArr *da, int initialCapacity);
/* internal method to double the capacity of a dynamic array */
void _dynArraySetCapacity(struct dynArr *da);
/* release dynamically allocated memory for the dynamic array */
void dynArrayFree(struct dynArr *da);
/* return number of elements stored in dynamic array */
int dynArraysize(struct dynArr *da);
/* add a value to the end of a dynamically array */
void dynArrayAdd(struct dynArr *da, TYPE e);
/* remove the value stored at position in the dynamic array */
void dynArrayRemoveAt(struct dynArr *da, int position);
/* retrieve element at a given position */
TYPE dynArrayGet(struct dynArr *da, int position);
/* store element at a given position */
void dynArrayPut(struct dynArr *da, int position, TYPE value);

#endif