#ifndef TYPE
#define TYPE double
#endif

#include <assert.h>

struct dynArr
{
    TYPE *data;   /* pointer to the data array */
    int size;     /* number of elements in the array */
    int capacity; /* capacity of the data array */
};

void dynArrayInit(struct dynArr *v, int capacity)
{
    v->data = (TYPE *)malloc(sizeof(TYPE) * capacity);
    assert(v->data != 0); // check if we got array
    v->size = 0;
    v->capacity = capacity;
}

void dynArrayFree(struct dynArr *v)
{
    if (v->data != 0)
    {
        free(v->data); /* free memory space */
        v->data = 0;   /* make it point to NULL */
    }
    v->size = 0;
    v->capacity = 0;
}

int dynArraySize(struct dynArr *v)
{
    return v->size;
}

void dynArrayAdd(struct dynArr *v, TYPE val)
{
    /* Check if a resize is necessary */
    if (v->size >= v->capacity)
        _dynArraySetCapacity(v, 2 * v->capacity);
    v->data[v->size] = val;
    v->size++;
}

void _dynArraySetCapacity(struct dynArr *v, int newCap)
{
    TYPE *newArr = (TYPE *)malloc(sizeof(TYPE) * newCap);

    assert(newArr != 0);

    int i = 0;
    while (i < v->size)
    {
        newArr[i] = v->data[i];
        i++;
    }

    // Free the old array to avoid memory leak
    free(v->data);

    // Assign the new array to v->data and update capacity
    v->data = newArr;
    v->capacity = newCap;
}

// getter and seeters for indexing

TYPE dynArrayGet(struct dynArr *da, int idx)
{
    assert(da != 0 && idx < da->size);

    return da->data[idx];
}

// void dynArrayPut(struct dynArr *da, int idx, TYPE val)
// {
//     assert(da != 0 && idx < da->size);

//     if (idx >= da->capacity) // > case is not possible.
//     {
//         _dynArraySetCapacity(da, 2 * da->capacity);
//     }

//     int i = idx;
//     while (i < da->size)
//     {
//         da->data[i + 1] = da->data[i];
//         i++;
//     }
//     da->data[idx] = val;
//     da->size++;
// }



void dynArrayInsert(struct dynArr *da, int idx, TYPE val)
{
    assert(da != 0 && idx >= 0 && idx <= da->size);

    if (da->size >= da->capacity)
        _dynArraySetCapacity(da, 2 * da->capacity);

    for (int i = da->size; i > idx; i--)
    {
        da->data[i] = da->data[i - 1];
    }

    da->data[idx] = val;
    da->size++;
}

void dynArraySwap(struct dynArr *da, int idx1, int idx2)
{
    assert(da != 0 && idx1 < da->size && idx2 < da->size);
    TYPE temp = da->data[idx1];
    da->data[idx1] = da->data[idx2];
    da->data[idx2] = temp;
}

void dynArrayRemoveAt(struct dynArr *da, int idx)
{
    assert(da != 0 && idx < da->size);
    int i = idx;
    while (i < da->size - 1)
    {
        da->data[i] = da->data[i + 1];
        i++;
    }
    da->size--;
}