#ifndef LIST_H
#define LIST_H

#include "support.h"

Support* insertHead(Support* head);
Support* insertTail(Support* head);
Support* deleteById(Support* head, int id);
void displayList(Support* head);
void searchSupport(Support* head, char keyword[]);

#endif
