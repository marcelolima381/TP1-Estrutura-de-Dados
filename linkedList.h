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

void insertAtBeginning(Node **head_ref, int new_data);
void insertAfterNode(Node *prev_node, int new_data);
void insertAtEnd(Node **head_ref, int new_data);
void insertBeforeNode(Node **head_ref, Node *next_node, int new_data);
void printList(Node *node);

#endif //TP1_ESTRUTURA_DE_DADOS_LINKEDLIST_H
