#include <stdio.h>
#include "linkedList.h"

int main() {
	Node* head = NULL;

	insertAtBeginning(&head, 7);
	insertAtBeginning(&head, 1);
	insertAtBeginning(&head, 4);
	insertBeforeNode(&head, head->next, 8);

	printf("Created DLL is: ");
	printList(head);
	getchar();

	return 0;
}