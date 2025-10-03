#ifndef TYPE
#define TYPE double
#endif

#include <assert.h>
#include <stdlib.h>

struct dynArr
{
    TYPE *data;
    int size;
    int capacity;
};

void _dynArraySetCapacity(struct dynArr *v, int newCap);

void dynArrayInit(struct dynArr *v, int capacity)
{
    v->data = (TYPE *)malloc(sizeof(TYPE) * capacity);
    assert(v->data != 0);
    v->size = 0;
    v->capacity = capacity;
}

void dynArrayFree(struct dynArr *v)
{
    if (v->data != 0)
    {
        free(v->data);
        v->data = 0;
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
    if (v->size >= v->capacity)
        _dynArraySetCapacity(v, 2 * v->capacity);
    v->data[v->size++] = val;
}

void _dynArraySetCapacity(struct dynArr *v, int newCap)
{
    assert(newCap >= v->size);
    TYPE *newArr = (TYPE *)malloc(sizeof(TYPE) * newCap);
    assert(newArr != 0);

    for (int i = 0; i < v->size; i++)
        newArr[i] = v->data[i];

    free(v->data);
    v->data = newArr;
    v->capacity = newCap;
}

TYPE dynArrayGet(struct dynArr *da, int idx)
{
    assert(da != 0 && idx < da->size);
    return da->data[idx];
}

void dynArrayPut(struct dynArr *da, int idx, TYPE val)
{
    assert(da != 0 && idx < da->size);
    da->data[idx] = val; // overwrite
}

void dynArrayInsert(struct dynArr *da, int idx, TYPE val)
{
    assert(da != 0 && idx >= 0 && idx <= da->size);

    if (da->size >= da->capacity)
        _dynArraySetCapacity(da, 2 * da->capacity);

    for (int i = da->size; i > idx; i--)
        da->data[i] = da->data[i - 1];

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
    for (int i = idx; i < da->size - 1; i++)
        da->data[i] = da->data[i + 1];
    da->size--;
}
