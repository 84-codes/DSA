#include "arrayBagStack.h"
#include <stddef.h>
#include<stdio.h>
/* Bag Implementation */
void initBag (struct arrayBagStack * b){
    b->count = 0;
} 



void addBag (struct arrayBagStack * b, TYPE v) {
    if(b == NULL) {
        // b is NULL then we can'tdo anything, the client should intialize data correctly
        return;
        // initBag(b);  b is NULL hence this does not make sense
        // b->data[0] = v;
    }
    if(b->count == MAX_SIZE) return;

    b->data[b->count] = v;
    b->count++;
}

int containsBag (struct arrayBagStack * b, TYPE v){
    if(b == NULL) return -1;     //empty bag cant have anything
    int i = b->count - 1;
    while(i>=0){
        if(v == b->data[i])
            return 1;
        i--;
    }
    return 0;
}

void removeBag (struct arrayBagStack * b, TYPE v) {
    if(b == NULL) return;
    int i = b->count - 1;
    // printf("size=%d\ncount=%d\n", i, b->count);
    while(i>=0){
        if(v == b->data[i]){
            //printf("size=%d\ncount=%d\n", i, b->count);
            b->data[i] = b->data[b->count-1];
            // don't need to shift items, as this is a bag. so even order doesnt matter, leave position in memory.
            // while(i < size){       // not <= because of i+1
            //     b->data[i] = b->data[i+1];
            //     i++;
            // }
            b->count--;
            return;
        }
        i--;
    }
}

int sizeBag (struct arrayBagStack * b) {
    return b->count;
}

// /* Stack Implementation */


void pushStack (struct arrayBagStack * b, TYPE v) {
    if(NULL == b) return;
    if(MAX_SIZE == b->count) return;
    b->data[b->count++] = v;          /// b-> is current size of array and stack, and hence new element goes here
}

TYPE topStack (struct arrayBagStack * b) {
    if(NULL == b || 0 == b->count) return -1; // or handle error appropriately
    return b->data[b->count - 1];      /// top element is at b->count -1
}

void popStack (struct arrayBagStack * b) {
    if(NULL == b || 0 == b->count) return;
    b->count--;
}

int isEmptyStack (struct arrayBagStack * b) {
    if(NULL == b || 0 == b->count) return 1;
    else return 0; 
}