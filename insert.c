#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
#include "insert.h"

// create node and allocate memory for it
Dlist_t * create_node(int data)
{
    // allocate memory
    Dlist_t *new = malloc(sizeof(Dlist_t));

    if (new == NULL)
    return NULL;

    // insert data and update address
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
status insert_at_first(Dlist_t **head, Dlist_t **tail, int data)
{
      // if there is no list
      if (*head == NULL )
      {
          Dlist_t *new = create_node(data);
          // update head
          *head = new;
          *tail = new;
          return Success;
      }

      // if head is not NULL create new node and change head
      Dlist_t *new = create_node(data);
      (*head)->prev = new;
      new->next = *head;
      *head = new;
      return Success;
}

status insert_at_last(Dlist_t **head, Dlist_t **tail, int data)
{
    // there is no list
    if (*head == NULL )
    {
        Dlist_t *new = create_node(data);
        // update head
        *head = new;
        *tail = new;
        return Success;
    }

    // create new node and update the tail
    Dlist_t *new = create_node(data);
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    return Success;
}


status insert_before(Dlist_t **head, Dlist_t **tail, int data, int key)
{
      // if there is not list
      if (*head == NULL)
      return Failure;

      // if head is the element
      if ( (*head)->data == key )
      {
          insert_at_first(head,tail,data);
          return Success;
      }

      // traverse the list find the element
      Dlist_t *ptr = *head;

      while (ptr && ptr->data != key )
      ptr = ptr->next;

      // if key not found
      if (ptr == NULL)
      return Failure;

      // key is found then create node and insert data
      Dlist_t *new = create_node(data);
      new->prev = ptr->prev;
      ptr->prev->next = new;
      ptr->prev = new;
      new->next = ptr;
      return Success;
}

status insert_after(Dlist_t **head, Dlist_t **tail, int data, int key)
{
    // if there is no list
    if (*head == NULL )
    return Failure;

    // if key is at tail insert at last
    if ((*tail)->data == key)
    {
      insert_at_last(head,tail,data);
      return Failure;
    }

    // traverse the list and find the data
    Dlist_t *ptr = *head;

    while (ptr && ptr->data != key )
    ptr = ptr->next;

    // if key not found
    if (ptr == NULL)
    return Failure;

    // key is found then create node and insert data
    Dlist_t *new = create_node(data);
    ptr->next->prev = new;
    new->next = ptr->next;
    ptr->next = new;
    new->prev = ptr; 
    return Success;
}
