# Code Review Report – Group 07 (Iterator & Mediator)

**Course:** CSE 3206 – Software Engineering Sessional, Lab 3
**Reviewer:** Abdullah Al Kafi ([@Kafi2611](https://github.com/Kafi2611))
**Code reviewed:**

| File | Pattern | Written by | Branch |
|---|---|---|---|
| `Iterator/iterator.cpp` | Iterator | Sadaf Rahman ([@sadaf532](https://github.com/sadaf532)) | `sadaf-iterator` |
| `Mediator/mediator.cpp` | Mediator | Sakila Akter ([@SakilaAkter](https://github.com/SakilaAkter)) | `sakila-mediator` |

Both files were reviewed in their pull requests on GitHub, approved, and merged into `main`.
We used the 10-point checklist from the lab sheet. **Good** = handled well, **Can improve** = a small issue we found.

## Review checklist

| Checklist item | Iterator code (`iterator.cpp`) | Mediator code (`mediator.cpp`) |
|---|---|---|
| Naming Convention | **Good** – classes use PascalCase (`BreakfastMenu`), functions use camelCase (`hasNext`). | **Good** – clear names: `ChatRoom`, `sendMessage`, `receive`. |
| SOLID Principles | **Good** – SRP (menu stores, iterator walks, client prints); OCP (a new menu needs no change in `printMenu`); DIP (client depends on interfaces). | **Good** – SRP (user talks, room routes); OCP (a new mediator type needs no change in `User`); DIP (`User` depends on `ChatMediator`). |
| Readability | **Good** – short classes, one comment above each part. | **Good** – short classes, comments explain each role. |
| Object Interaction | **Good** – client → menu → iterator; the client only calls `hasNext()` / `next()`. | **Good** – user → room → other users; no direct user-to-user call. |
| Pattern Correctness | **Good** – all GoF roles present: Iterator, Concrete Iterator, Aggregate, Concrete Aggregate, Client. | **Good** – all GoF roles present: Mediator, Concrete Mediator, Colleague, Client. |
| Reusability | **Good** – `ArrayIterator` / `VectorIterator` can be reused by any class that stores strings. | **Good** – `User` works with any `ChatMediator`. |
| Exception Handling | **Can improve** – `next()` does not check `hasNext()`; calling it after the end reads outside the array. | **Can improve** – the room does not check that the sender is a member, or that `chat` is not null. |
| Documentation | **Good** – comments name each pattern role; short comments on each function could be added. | **Good** – comments name each pattern role; short comments on each function could be added. |
| Maintainability | **Good** – adding a menu touches only new classes. | **Good** – message rules live in one class (`ChatRoom`). |
| Efficiency | **Good** – O(n) walk, no copying of items. **Can improve** – raw `new`/`delete` for each walk. | **Good** – O(n) per message. **Can improve** – raw pointers mean users must live longer than the room. |

## Suggested improvements

1. **Safe `next()`** – throw an exception at the end:
   ```cpp
   if (!hasNext()) throw out_of_range("No more items");
   ```
2. **Smart pointers** – return `unique_ptr<Iterator>` from `createIterator()`, so the iterator is deleted automatically.
3. **Member check** – in `ChatRoom::sendMessage()`, ignore messages from users who were never added to the room.
4. **const-correctness** – write `string getName() const` because the function does not change the object.

We kept the main code short on purpose so that each pattern is easy to see and explain. These changes can be added for a real project.

## Result

| File | Decision |
|---|---|
| `Iterator/iterator.cpp` | ✅ Approved and merged |
| `Mediator/mediator.cpp` | ✅ Approved and merged |
