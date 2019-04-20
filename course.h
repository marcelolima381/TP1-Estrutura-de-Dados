//
// Created by marcelo on 19/04/19.
//

#ifndef TP1_ESTRUTURA_DE_DADOS_COURSE_H
#define TP1_ESTRUTURA_DE_DADOS_COURSE_H
#ifndef INITIAL_SIZE
#define INITIAL_SIZE 2
#endif
#include "linkedList.h"

typedef struct course Course;
struct course {
	char *name;
	int numberOfVacancies;
	Node *vacancies;
};

void removeLastChar(char *str);
char* readDynamicString();
char* setCourseName();
int setNumberOfVacancies();
Course registerCourse();
void registerCourses(int numberOfCourses, Course *courses);

#endif //TP1_ESTRUTURA_DE_DADOS_COURSE_H
