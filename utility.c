#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
#include "utility.h"

status print_list(Dlist_t *head)
{
    // if there is no list return failure
    if ( head == NULL )
    return Failure;

    Dlist_t *ptr = head;

    // traverse list
    while (ptr)
    {
        printf("|%p|%d|%p|->",ptr->prev, ptr->data, ptr->next);
        ptr = ptr->next;
    }

    printf("\n");

    return Success;
}

status reverse_list(Dlist_t **head, Dlist_t **tail)
{
    // if there is no list return failure
    if ( *head == NULL )
    return Failure;

    // swap prev and next of the list
    Dlist_t *ptr = *head, *temp,*curr = *head;
    // change the tail and head
    temp = *tail;
    *tail = *head;
    *head = temp;

    while(curr)
    {
        ptr = curr;
        curr = curr->next;
        temp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = temp;
    }

    return Success;
}
