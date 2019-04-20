//
// Created by marcelo on 11/04/19.
//

#ifndef TP1_ESTRUTURA_DE_DADOS_LINKEDLIST_H
#define TP1_ESTRUTURA_DE_DADOS_LINKEDLIST_H

typedef struct node Node;
struct node {
	int data;
	Node *next;
	Node *previous;
};

void insertAtBeginning(Node **headRef, int newData);
void insertAfterNode(Node *prevNode, int newData);
void insertAtEnd(Node **headRef, int newData);
void insertBeforeNode(Node **headRef, Node *nextNode, int newData);
void printList(Node *node);

#endif //TP1_ESTRUTURA_DE_DADOS_LINKEDLIST_H
