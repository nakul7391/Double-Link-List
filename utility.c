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
