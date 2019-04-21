//
// Created by marcelo on 20/04/19.
//

#ifndef TP1_ESTRUTURA_DE_DADOS_STUDENT_H
#define TP1_ESTRUTURA_DE_DADOS_STUDENT_H

typedef struct student Student;
struct student {
	char *name;
	float score;
	int firstOption;
	int secondOption;
};

void registerStudents(int numberOfStudents, Student *students);
Student* setStudent();

#endif //TP1_ESTRUTURA_DE_DADOS_STUDENT_H
