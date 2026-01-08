#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"



Stack* push(Stack* top, char action[]) {
    Stack* s = malloc(sizeof(Stack));
    if (!s) return top;
    strcpy(s->action, action);
    s->next = top;
    return s;
}

Stack* pop(Stack* top) {
    if (!top) return NULL;
    Stack* tmp = top;
    top = top->next;
    free(tmp);
    return top;
}

void displayStack(Stack* top) {
    if (!top) {
        printf("History empty.\n");
        return;
    }
    while (top) {
        printf("- %s\n", top->action);
        top = top->next;
    }
}
