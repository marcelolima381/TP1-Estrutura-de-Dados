//
// Created by marcelo on 11/04/19.
//

#ifndef TP1_ESTRUTURA_DE_DADOS_LINKEDLIST_H
#define TP1_ESTRUTURA_DE_DADOS_LINKEDLIST_H

#include "datatype.h"

void insertAtBeginning(Node **headRef, Student *newStudent);
void insertAfterNode(Node *prevNode, Student *newStudent);
void insertAtEnd(Node **headRef, Student *newStudent);
void insertBeforeNode(Node **node, Student *newStudent);
void insertBeforePreviousNull(Node *node, Student *newStudent);
void rewindList(Course *course);
void printList(Node *node);

#endif //TP1_ESTRUTURA_DE_DADOS_LINKEDLIST_H
