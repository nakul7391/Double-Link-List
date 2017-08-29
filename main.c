/*Implementation of double link list */
#include <stdio.h>
#include "prototype.h"
#include "utility.h"
#include "insert.h"
#include "delete.h"

int main(int argc, char *argv[] )
{
		Dlist_t *head = NULL, *tail = NULL;

		// insert data at first 5->
		insert_at_first(&head, &tail, 5);

		// insert data at last 5->10
		insert_at_last(&head, &tail, 10);

		// insert after 5->10->20
		insert_after(&head, &tail, 20, 10);

		// insert before 5->10->15->20
		insert_before(&head, &tail, 15,20);

		// print list
		print_list(head);

		printf("Deleting First\n");
		// delete first 10->15->20
		delete_first(&head,&tail);
		print_list(head);

		printf("Deleting Last\n");
		// delete last node 10->15
		delete_last(&head,&tail);
		print_list(head);

		printf("Insert at last\n");
		// insert at last 10->15->128
		insert_at_last(&head, &tail, 128);
		print_list(head);

		printf("delete 128\n");
		// delete 128 10->15
		delete_element(&head, &tail, 128);
		print_list(head);
		// print list

		printf("Reverse list\n");
		//reverse list
		reverse_list(&head,&tail);

		// print list 15->10
		print_list(head);
		return 0;
}
