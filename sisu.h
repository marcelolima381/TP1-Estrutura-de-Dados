//
// Created by marcelo on 21/04/19.
//

#ifndef TP1_ESTRUTURA_DE_DADOS_SISU_H
#define TP1_ESTRUTURA_DE_DADOS_SISU_H
//#include "student.h"
//#include "course.h"

#include "datatype.h"

void secondOption();
int checkListEmpty(int size);
int courseIsFull(int size, int numberOfVacancies);
void insertAtFullCourse(Course *course, Node *last, Node *node, Student *student, float score);
void insertAtHungryCourse(Course *course, Node *node, Student *student, float score);
void manageCourseVacancies(Course *course, Node *last, Node *node, Student *student, int size, float score);
void showSisuResult(Course *courses, Student *students, int numberOfStudents);

#endif //TP1_ESTRUTURA_DE_DADOS_SISU_H
