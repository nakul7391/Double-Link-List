#ifndef DELETE_H
#define DELETE_H

// function to delete first element
status delete_first(Dlist_t **head, Dlist_t **tail);

// function to delete last element
status delete_last(Dlist_t **head, Dlist_t **tail);

// function to delete a given key
status delete_element(Dlist_t **head, Dlist_t **tail, int key);
#endif
