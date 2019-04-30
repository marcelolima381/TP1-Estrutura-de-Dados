//
// Created by marcelo on 21/04/19.
//

#ifndef TP1_ESTRUTURA_DE_DADOS_SISU_H
#define TP1_ESTRUTURA_DE_DADOS_SISU_H

#include "datatype.h"

void secondOption(Student *student);
int checkListEmpty(int size);
int courseIsFull(int size, int numberOfVacancies);
void insertAtFullCourse(Course *courses, Node *last, Node *node, Student *student, float score, int option);
void insertAtHungryCourse(Course *courses, Node *node, Student *student, float score, int option);
void manageCourseVacancies(Course *courses,
						   Node *last,
						   Node *node,
						   Student *student,
						   int size,
						   float score,
						   int option);
int getListSize(Node *node, Node **last);
void showSisuResult(Course *courses, Student *students, int numberOfStudents);

#endif //TP1_ESTRUTURA_DE_DADOS_SISU_H
