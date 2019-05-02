//
// Created by marcelo on 21/04/19.
//

#ifndef TP1_ESTRUTURA_DE_DADOS_SISU_H
#define TP1_ESTRUTURA_DE_DADOS_SISU_H

#include "datatype.h"
void manageCourseVacancies(Course *courses,
						   Node *last,
						   Node *node,
						   Student *student,
						   int size,
						   int option);
int checkListEmpty(int size);
int courseIsFull(int size, int numberOfVacancies);
void insertAtFullNode(Course *courses, Node *last, Node *node, Student *student, int option);
void insertAtHungryNode(Course *courses, Node **node, Student *student, int option);
void insertAtWaitingList(Course *courses, Student *student, int option);
int getListSize(Node *node, Node **last);
void showSisuResult(Course *courses, Student *students, int numberOfStudents, int numberOfCourses);

#endif //TP1_ESTRUTURA_DE_DADOS_SISU_H
