#include <stdio.h>
#include <string.h>
#include "list.h"
#include "stack.h"
#include "list.h"
#include "support.h"


int main() {
    Support* list = NULL;
    Stack* history = NULL;
    int choice, id;
    char key[100];

    do {
        printf("\n==== COURSE MATERIAL MANAGEMENT ====\n");
        printf("1. Add support (head)\n");
        printf("2. Add support (tail)\n");
        printf("3. Display supports\n");
        printf("4. Search support\n");
        printf("5. Delete support\n");
        printf("6. View history\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice); getchar();

        switch (choice) {
            case 1:
                list = insertHead(list);
                history = push(history, "Added support (head)");
                break;
            case 2:
                list = insertTail(list);
                history = push(history, "Added support (tail)");
                break;
            case 3:
                displayList(list);
                break;
            case 4:
                printf("Keyword: ");
                fgets(key, 100, stdin);
                searchSupport(list, key);
                break;
            case 5:
                printf("ID to delete: ");
                scanf("%d", &id);
                list = deleteById(list, id);
                history = push(history, "Deleted support");
                break;
            case 6:
                displayStack(history);
                break;
        }
    } while (choice != 0);

    return 0;
}
