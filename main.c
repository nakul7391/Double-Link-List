/*Implementation of double link list */
#include <stdio.h>
#include "prototype.h"
#include "utility.h"
#include "insert.h"
#include "delete.h"

int main(int argc, char *argv[] )
{
		Dlist_t *head = NULL, *tail = NULL;

		insert_at_last(&head, &tail, 5);
		insert_at_last(&head, &tail, 10);
		insert_at_last(&head, &tail, 15);
		insert_at_last(&head, &tail, 20);
		print_list(head);
		reverse_list(&head,&tail);
		print_list(head);
		return 0;
}
