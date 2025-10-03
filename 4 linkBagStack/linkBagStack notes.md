Stack is a structure, which essential points to a link.

struct ListStack {
struct Link * sentinel;
};

A limk points to another link and has data.

struct Link {
TYPE value;
struct Link * next;
};


Hence intializing requries assining a link to the sentiel (sentiel = 0). 

===============================================================================================================

# static vs dynamic allocation

## ✅ Version 1: Using `malloc` (Dynamic Allocation)

```c
struct link *newLink = (struct link *)malloc(sizeof(struct link));
newLink->next = s->sentinel;
newLink->value = d;

s->sentinel = newLink;
```

### ✔ What Happens:

* Allocates memory on the **heap**.
* `newLink` persists **after the function returns**.
* Safe to assign `s->sentinel = newLink` — this is how linked lists usually work.

✅ **Correct.**
💡 This is the standard and correct way to add a new node to a linked list dynamically.

---

## ❌ Version 2: Stack Allocation (Local Variable)

```c
struct link newLink;
newLink.next = s->sentinel;
newLink.value = d;

s->sentinel = &newLink;
```

### ⚠ What Happens:

* `newLink` is allocated on the **stack** — it's a local variable.
* When the function exits, `newLink` is **destroyed**.
* But `s->sentinel` still points to its address (`&newLink`) — a **dangling pointer**.
* Accessing `s->sentinel` later will lead to **undefined behavior** (crashes, garbage data).

❌ **Incorrect. Dangerous.**

---

## 🔁 Summary Table:

| Version          | Allocation Type | Safe to use after function exits? | Behavior             |
| ---------------- | --------------- | --------------------------------- | -------------------- |
| 1 (`malloc`)     | Heap            | ✅ Yes                             | ✅ Correct            |
| 2 (local struct) | Stack           | ❌ No                              | ❌ Undefined behavior |

---

===============================================================================================================

free(*s->sentinel);
is wrong (undefined behaviour) as free expects a poiner.

===============================================================================================================

Wheater to include a header file in .c or .h file?

| File Type | Include `<stdlib.h>` / `<assert.h>`?                        |
| --------- | ----------------------------------------------------------- |
| `.h` file | ❌ No (unless types/macros from them are used in the header) |
| `.c` file | ✅ Yes (if you use `malloc`, `free`, `assert`, etc.)         |

===============================================================================================================

