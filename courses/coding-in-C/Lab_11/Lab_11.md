# Lab 11: Stacks and Queues
This lab focuses on stacks and queues. In does not contain any fancy project. The idea is to double down on the concepts of linked lists and repeating the implementation until it is fully mastered.

Why is this important: Linked lists and therefore stacks/queues based on them, include many central concepts of C such as dynamic memory allocation, pointer usage and structs.

In short:
- If you really understand linked lists, you understand C.
- If you really can code linked lists, you can code in C.

---
## Section I: Linked lists

### Task Description
1. Watch the tutorial on how to code a [linked list in C](https://www.youtube.com/watch?v=CF2T9oJv2mQ) or another freely available tutorial on e.g. youtube.
2. Understand how the linked list and its basic functions are implemented.
3. Re-implement the code by yourself.
4. Test the list logic by calling the corresponding functions in the main function.
5. If you were not able to implement it after watching the tutorial by yourself, identify the topics you did not understand.
6. Each of these topics should be investigated by you with the help of your colleagues, your favourite search engine, AI or your professor.
7. Repeat at step 3 until you master the linked list implementation in C.
---

### Notes

- Note that the code in the linked video is not completely idiomatic because the sizeof operator is used with the target datatype instead of the variable. E.g.:
```c
ListElement *a = malloc(sizeof(ListElement)); // this is not completely idiomatic

ListElement *a = malloc(sizeof *a);    // better since we use the target variable in sizeof
```

---


## Section II: Stacks

### Task Description
1. Watch the tutorial on how to code a [stack in C](https://www.youtube.com/watch?v=DdyI_4Tu4f4&t=5s) or another freely available tutorial on e.g. youtube.
2. Understand how the stack and its basic functions are implemented using a linked list.
3. Re-implement the code by yourself.
4. Test the stack logic by calling the corresponding functions in the main function.
5. If you were not able to implement it after watching the tutorial by yourself, identify the topics you did not understand.
6. Each of these topics should be investigated by you with the help of your colleagues, your favourite search engine, AI or your professor.
7. Repeat at step 3 until you master the stack implementation in C.
---

### Notes

- Note that the code in the linked video is not completely idiomatic because the sizeof operator is used with the target datatype instead of the variable. E.g.:
```c
Stack *s = malloc(sizeof(Stack)); // this is not completely idiomatic

Stack *s = malloc(sizeof *s);    // better since we use the target variable in sizeof
```

---

## Section III: Queues

### Task Description
1. Watch the tutorial on how to code a [queue in C](https://www.youtube.com/watch?v=yKNPFKfnlt8) or another freely available tutorial on e.g. youtube.
2. Understand how the queue and its basic functions are implemented using a linked list.
3. Re-implement the code by yourself.
4. Test the queue logic by calling the corresponding functions in the main function.
5. If you were not able to implement it after watching the tutorial by yourself, identify the topics you did not understand.
6. Each of these topics should be investigated by you with the help of your colleagues, your favourite search engine, AI or your professor.
7. Repeat at step 3 until you master the queue implementation in C.
---

### Notes

- Note that the code in the linked video is not completely idiomatic because the sizeof operator is used with the target datatype instead of the variable. E.g.:
```c
Queue *q = malloc(sizeof(Queue)); // this is not completely idiomatic

Queue *q = malloc(sizeof *q);    // better since we use the target variable in sizeof
```