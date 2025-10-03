#include <stdio.h>
#include "arrayBagStack.h"

void testBagFunctions() {
    printf("=== Bag Function Tests ===\n");

    struct arrayBagStack bag;
    initBag(&bag);

    printf("Adding 10, 20, 30 to bag...\n");
    addBag(&bag, 10);
    addBag(&bag, 20);
    addBag(&bag, 30);

    printf("Current bag size: %d\n", sizeBag(&bag));

    printf("Does bag contain 20? %s\n", containsBag(&bag, 20) ? "Yes" : "No");
    printf("Does bag contain 40? %s\n", containsBag(&bag, 40) ? "Yes" : "No");

    printf("Removing 20...\n");
    removeBag(&bag, 20);
    printf("Does bag contain 20? %s\n", containsBag(&bag, 20) ? "Yes" : "No");
    printf("Bag size after removal: %d\n", sizeBag(&bag));
}

void testStackFunctions() {
    printf("\n=== Stack Function Tests ===\n");

    struct arrayBagStack stack;
    initBag(&stack);

    printf("Pushing 5, 15, 25 onto stack...\n");
    pushStack(&stack, 5);
    pushStack(&stack, 15);
    pushStack(&stack, 25);

    printf("Top of stack: %d\n", topStack(&stack));
    printf("Is stack empty? %s\n", isEmptyStack(&stack) ? "Yes" : "No");

    printf("Popping top element...\n");
    popStack(&stack);
    printf("Top of stack now: %d\n", topStack(&stack));

    printf("Popping all elements...\n");
    popStack(&stack);
    popStack(&stack);
    printf("Is stack empty after popping all? %s\n", isEmptyStack(&stack) ? "Yes" : "No");
}

int main() {
    testBagFunctions();
    testStackFunctions();
    return 0;
}
