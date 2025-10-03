/* =====================================================
 * AUTHOR: Shekhar C.
 * Date: 03/10/2025
 * Time: 19:07
 * Description:
 *      implementing only removing.....
 *      and search (contains operation)
===================================================== */
#include <assert.h>
#define EQ(a, b) (a == b)

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

int containsBag(struct linkedListStack *b, EleType v)
{
    assert(b != 0);
}

// remove all
void removeBag(struct linkedListStack *b, EleType v)
{
    assert(b != 0);
    struct link *previous = b->sentinel;
    struct link *current = b->sentinel->next;

    while (!current)
    {
        if (EQ(current->value, v))
        {
            previous->next = current->next; // we are updating the 'next' of the link "behind" the node that is deleted to the element ahead of it.
            free(current);
            current = previous; // remove all, if single return here
        }
        previous = current;
        current = current->next;
    }
}
