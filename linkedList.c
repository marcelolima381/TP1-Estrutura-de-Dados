//
// Created by marcelo on 11/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void insertAtBeginning(Node **headRef, int newData) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = (*headRef);
	newNode->previous = NULL;
	if ((*headRef) != NULL)
		(*headRef)->previous = newNode;
	(*headRef) = newNode;
}

void insertAfterNode(Node *previousNode, int newData) {
	if (previousNode == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = previousNode->next;
	previousNode->next = newNode;
	newNode->previous = previousNode;
	if (newNode->next != NULL)
		newNode->next->previous = newNode;
}

void insertAtEnd(Node **headRef, int newData) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	Node *last = *headRef;
	newNode->data = newData;
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

void insertBeforeNode(Node **headRef, Node *nextNode, int newData) {
	if (nextNode == NULL) {
		printf("the given next node cannot be NULL");
		return;
	}

	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = newData;
	newNode->previous = nextNode->previous;
	nextNode->previous = newNode;
	newNode->next = nextNode;
	if (newNode->previous != NULL)
		newNode->previous->next = newNode;
	else
		(*headRef) = newNode;

}

void printList(Node *node) {
	Node *last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->data);
		last = last->previous;
	}
}  