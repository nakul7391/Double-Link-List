#ifndef INSERT_H
#define INSERT_H

// function to create node in the list
Dlist_t * create_node(int data);

// function to insert data at first
status insert_at_first(Dlist_t **head, Dlist_t **tail, int data);

// function to insert data at last
status insert_at_last(Dlist_t **head, Dlist_t **tail, int data);

// function to insert data before given key
status insert_before(Dlist_t **head, Dlist_t **tail, int data, int key);

// function to insert data after given key
status insert_after(Dlist_t **head, Dlist_t **tail, int data, int key);
#endif
