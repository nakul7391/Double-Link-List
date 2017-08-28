#ifndef PROTOTYPE_H
#define PROTOTYPE_H

// double link list prototype
typedef struct Dlist
{
    int data;
    struct Dlist *prev; // pointer to hold address of previous node
    struct Dlist *next; // pointer to hold address of next node
} Dlist_t;

// return status
typedef enum
{
  Failure,
  Success
} status;

#endif
