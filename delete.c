#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
#include "delete.h"

status delete_first(Dlist_t **head, Dlist_t **tail)
{
    // if there is no list return failure
    if (*head == NULL)
    return Failure;

    // if list contain only one element then delete entire list
    if (*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
        return Success;
    }

    // delete head node and update head node
    Dlist_t *ptr = *head;

    // connect links
    *head = ptr->next;
    (*head)->prev = NULL;
    free(ptr);
    return Success;
}

status delete_last(Dlist_t **head, Dlist_t **tail)
{
    // if there is not list return Failure
    if (*head == NULL)
    return Failure;

    // if list contain only one element
    if (*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
        return Success;
    }

    // remove last node and update tail
    Dlist_t *ptr = *tail;

    // update the tail
    *tail = ptr->prev;
    (*tail)->next = NULL;
    free(ptr);
    return Success;
}

status delete_element(Dlist_t **head, Dlist_t **tail, int key)
{
    // if there is no list
    if (*head == NULL )
    return Failure;

    // if head contains the key
    if ((*head)->data == key)
    {
      delete_first(head,tail);
      return Success;
    }

    // if tail contain the data
    if((*tail)->data == key)
    {
        delete_last(head,tail);
        return Success;
    }

    // find the element
    Dlist_t *ptr = *head;

    // traverse the list
    while (ptr && ptr->data != key)
    ptr = ptr->next;

    // if element is not found
    if (ptr == NULL )
    return Failure;

    // delete the node and connet links
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return Success;
}
