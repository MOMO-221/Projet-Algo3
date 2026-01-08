#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    char action[100];
    struct Stack* next;
} Stack;

Stack* push(Stack* top, char action[]);
Stack* pop(Stack* top);
void displayStack(Stack* top);

#endif
