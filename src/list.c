#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "stack.h"
#include "list.h"
#include "support.h"


Support* createSupport() {
    Support* s = malloc(sizeof(Support));
    if (!s) return NULL;

    printf("ID: "); scanf("%d", &s->id); getchar();
    printf("Title: "); fgets(s->title, 100, stdin);
    printf("Module: "); fgets(s->module, 100, stdin);
    printf("Type: "); fgets(s->type, 50, stdin);
    printf("Teacher: "); fgets(s->teacher, 100, stdin);
    printf("Date: "); fgets(s->date, 20, stdin);

    s->next = NULL;
    return s;
}

Support* insertHead(Support* head) {
    Support* s = createSupport();
    if (!s) return head;
    s->next = head;
    return s;
}

Support* insertTail(Support* head) {
    Support* s = createSupport();
    if (!s) return head;

    if (!head) return s;

    Support* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = s;
    return head;
}

Support* deleteById(Support* head, int id) {
    if (!head) return NULL;

    if (head->id == id) {
        Support* tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    Support* cur = head;
    while (cur->next && cur->next->id != id)
        cur = cur->next;

    if (cur->next) {
        Support* tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
    }
    return head;
}

void displayList(Support* head) {
    if (!head) {
        printf("No supports.\n");
        return;
    }

    while (head) {
        printf("\nID:%d | %s | %s | %s",
               head->id, head->title, head->module, head->teacher);
        head = head->next;
    }
}

void searchSupport(Support* head, char keyword[]) {
    int found = 0;
    while (head) {
        if (strstr(head->title, keyword) ||
            strstr(head->module, keyword)) {
            printf("Found: %d - %s", head->id, head->title);
            found = 1;
        }
        head = head->next;
    }
    if (!found) printf("No match found.\n");
}
