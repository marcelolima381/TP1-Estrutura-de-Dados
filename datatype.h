//
// Created by marcelo on 25/04/19.
//

#ifndef TP1_ESTRUTURA_DE_DADOS_DATATYPE_H
#define TP1_ESTRUTURA_DE_DADOS_DATATYPE_H

typedef struct student Student;
struct student {
	char *name;
	float score;
	int firstOption;
	int secondOption;
};

typedef struct node Node;
struct node {
	Student *student;
	Node *next;
	Node *previous;
};

typedef struct course Course;
struct course {
	char *name;
	int numberOfVacancies;
	Node *vacancies;
	Node *waitingList;
};

#endif //TP1_ESTRUTURA_DE_DADOS_DATATYPE_H
