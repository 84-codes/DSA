#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

typedef int EleType;

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
void linkedListStackInit(struct linkedListStack *s);

// Frees all elements from the stack
void linkedListStackFree(struct linkedListStack *s);

// Pushes an element onto the stack
void linkedListStackPush(struct linkedListStack *s, EleType d);

// Returns the top element of the stack (without removing it)
EleType linkedListStackTop(struct linkedListStack *s);

// Removes the top element from the stack
void linkedListStackPop(struct linkedListStack *s);

// Checks whether the stack is empty
int linkedListStackIsEmpty(struct linkedListStack *s);

#endif // LINKED_LIST_STACK_H
