//
// Created by marcelo on 11/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void insertAtBeginning(Node **headRef, Student *newStudent) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->student = newStudent;
	newNode->next = (*headRef);
	newNode->previous = NULL;
	if ((*headRef) != NULL)
		(*headRef)->previous = newNode;
	(*headRef) = newNode;
}

void insertAfterNode(Node *previousNode, Student *newStudent) {
	if (previousNode == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->student = newStudent;
	newNode->next = previousNode->next;
	previousNode->next = newNode;
	newNode->previous = previousNode;
	if (newNode->next != NULL)
		newNode->next->previous = newNode;
}

void insertAtEnd(Node **headRef, Student *newStudent) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	Node *last = *headRef;
	newNode->student = newStudent;
	newNode->next = NULL;
	if (*headRef == NULL) {
		newNode->previous = NULL;
		*headRef = newNode;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newNode;
	newNode->previous = last;
}

void insertBeforeNode(Node **headRef, Node *nextNode, Student *newStudent) {
	if (nextNode == NULL) {
		printf("the given next node cannot be NULL");
		return;
	}

	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->student = newStudent;
	newNode->previous = nextNode->previous;
	nextNode->previous = newNode;
	newNode->next = nextNode;
	if (newNode->previous != NULL)
		newNode->previous->next = newNode;
	else
		(*headRef) = newNode;

}

void printList(Node *node) {
	Node *last = NULL;
//	printf("\nTraversal in forward direction \n");
	if (node == NULL) {
		printf("NODE NULO!\n");
	}
	while (node != NULL) {
		printf("Nome: %s\n | Primeira opcao: %i\n | Segunda opcao: %i\n | Nota: %.2f\n\n", node->student->name, node->student->firstOption, node->student->secondOption, node->student->score);
		last = node;
		node = node->next;
	}

	/*printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf("Nome: %s\n | Primeira opcao: %i\n | Segunda opcao: %i\n\n", last->student->name, last->student->firstOption, last->student->secondOption);
		last = last->previous;
	}*/
}  