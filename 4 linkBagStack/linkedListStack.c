#include "linkedListStack.h"

struct link
{
    EleType value;
    struct link *next;
};

struct linkedListStack
{
    struct link *sentinel;
};

// Initializes the stack
void linkedListStackInit(struct linkedListStack *s)
{
    s->sentinel = 0;
}

// Frees all elements from the stack
void linkedListStackFree(struct linkedListStack *s)
{
    while (!linkedListStackIsEmpty(s))
    {
        linkedListStackPop(s);
    }
}

// Pushes an element onto the stack
void linkedListStackPush(struct linkedListStack *s, EleType d)
{
    // 2 step process

    // 1. create the new link with value and make its next point to the current start
    struct link *newLink = (struct link *)malloc(sizeof(struct link));
    assert(newLink != 0);
    newLink->next = s->sentinel;
    newLink->value = d;

    // 2. set sentinel to newlink.
    s->sentinel = newLink;
}

// Returns the top element of the stack (without removing it)
EleType linkedListStackTop(struct linkedListStack *s)
{
    assert(s->sentinel != 0);
    return s->sentinel->value;
}

// Removes the top element from the stack
void linkedListStackPop(struct linkedListStack *s)
{
    assert(s->sentinel != 0);
    struct link *temp = s->sentinel->next;
    free(s->sentinel);
    s->sentinel = temp;
}

// Checks whether the stack is empty
int linkedListStackIsEmpty(struct linkedListStack *s)
{
    return 0 == s->sentinel;
}
