#include "/home/skc/Documents/zDev/DSA/lib/Unity/src/unity.h"
#include "linkedListStack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct linkedListStack stack;

void setUp(void)
{
    linkedListStackInit(&stack);
}

void tearDown(void)
{
    linkedListStackFree(&stack);
}

void test_StackIsEmptyOnInit(void)
{
    TEST_ASSERT_TRUE(linkedListStackIsEmpty(&stack));
}

void test_PushAddsElement(void)
{
    linkedListStackPush(&stack, 10);
    TEST_ASSERT_FALSE(linkedListStackIsEmpty(&stack));
    TEST_ASSERT_EQUAL_INT(10, linkedListStackTop(&stack));
}

void test_PushMultipleElements(void)
{
    linkedListStackPush(&stack, 1);
    linkedListStackPush(&stack, 2);
    linkedListStackPush(&stack, 3);

    TEST_ASSERT_EQUAL_INT(3, linkedListStackTop(&stack));
    linkedListStackPop(&stack);
    TEST_ASSERT_EQUAL_INT(2, linkedListStackTop(&stack));
    linkedListStackPop(&stack);
    TEST_ASSERT_EQUAL_INT(1, linkedListStackTop(&stack));
}

void test_FreeCleansStack(void)
{
    linkedListStackPush(&stack, 5);
    linkedListStackPush(&stack, 6);
    linkedListStackFree(&stack);

    TEST_ASSERT_TRUE(linkedListStackIsEmpty(&stack));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_StackIsEmptyOnInit);
    RUN_TEST(test_PushAddsElement);
    RUN_TEST(test_PushMultipleElements);
    RUN_TEST(test_FreeCleansStack);

    return UNITY_END();
}
