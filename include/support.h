#ifndef SUPPORT_H
#define SUPPORT_H

typedef struct Support {
    int id;
    char title[100];
    char module[100];
    char type[50];
    char teacher[100];
    char date[20];
    struct Support* next;
} Support;

#endif
