//
// Created by marcelo on 21/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "linkedList.h"
#include "utils.h"

int checkListEmpty(int size) {
	return size == 0 ? 1 : 0;
}

int courseIsFull(int size, int numberOfVacancies) {
	return size == numberOfVacancies ? 1 : 0;
}

int getListSize(Node *node, Node **last) {
	int size = 0;
	while (node != NULL) {
		size++;
		*last = node;
		node = node->next;
	}

	return size;
}

void insertAtHungryNode(Course *courses, Node **node, Student *student, int option) {
//	node = courses[option].vacancies;
	Node *nodeValue = *node;
	while (*node != NULL) {
		if (nodeValue->student->score < student->score) {
			if (nodeValue->previous != NULL) {
				insertBeforePreviousNull(*node, student);
			} else {
				insertBeforeNode(node, student);
			}
//			courses[option].vacancies = node;
			break;
		} else if (nodeValue->student->score >= student->score && nodeValue->next == NULL) {
			insertAtEnd(node, student);
			break;
		}
		nodeValue = nodeValue->next;
	}
}

void insertAtWaitingList(Course *courses, Student *student, int option) {
	Node *lastWaitingList;
	int size = getListSize(courses[option].waitingList, &lastWaitingList);
	if (checkListEmpty(size)) {
		insertAtBeginning(&courses[option].waitingList, student);
	} else {
		insertAtHungryNode(courses,
						   &courses[option].waitingList,
						   student,
						   option);
	}
}

void insertAtFullNode(Course *courses, Node *last, Node *node, Student *student, int option) {
//	node = courses[option].vacancies;
	while (node != NULL) {
		if (node->student->score < student->score) {
			if (node->previous == NULL) {
				insertAtBeginning(&node, student);
			} else {
				insertAfterNode(node->previous, student);
			}
			Student *disclassifiedStudent = last->student;
			last->previous->next = NULL;
//
			insertAtWaitingList(courses, disclassifiedStudent, option);
			if (option != disclassifiedStudent->secondOption) {
				secondOption(courses, &courses[disclassifiedStudent->secondOption].vacancies, disclassifiedStudent);
			}
			break;
		}
		node = node->next;
	}
}

void manageCourseVacancies(Course *courses,
						   Node *last,
						   Node *node,
						   Student *student,
						   int size,
						   int option) {
	if (courseIsFull(size, courses[option].numberOfVacancies)) {
		if (last->student->score >= student->score && option != student->secondOption) {
			insertAtWaitingList(courses, student, option);
			secondOption(courses, &courses[student->secondOption].vacancies, student);
		} else if(last->student->score >= student->score && option == student->secondOption) {
			insertAtWaitingList(courses, student, option);
		} else {
			insertAtFullNode(courses, last, node, student, option);
		}
	} else {
		insertAtHungryNode(courses, &node, student, option);
	}
}

void showSisuResult(Course *courses, Student *students, int numberOfStudents, int numberOfCourses) {
	int i;
	int firstOption;
	int secondOption;

	for (i = 0; i < numberOfStudents; i++) {
//		printf("P DE DOUG é igual a %i\n", i);
		firstOption = students[i].firstOption;
		secondOption = students[i].secondOption;

//		printf("%s %.2f\n", students[i].name, students[i].score);

		Node *node = courses[firstOption].vacancies;
		Node *last;
		int size = getListSize(node, &last);

		if (checkListEmpty(size)) {
			insertAtBeginning(&courses[firstOption].vacancies, &students[i]);
		} else {
			manageCourseVacancies(courses, last, node, &students[i], size, firstOption);
		}

		rewindList(&courses[firstOption]);
		rewindList(&courses[secondOption]);
	}

	/*printList(courses[0].vacancies);
	printf("___________________________________\n");
	printList(courses[0].waitingList);
	printf("***\n");
	printList(courses[1].vacancies);
	printf("___________________________________\n");
	printList(courses[1].waitingList);
	printf("---\n");
	printf("---\n");
	printf("---\n");*/


	Node *last = (Node *) malloc (sizeof(Node));
	for (i = 0; i < numberOfCourses; i++) {
		Node *walker = courses[i].vacancies;
		if (walker == NULL) {
			printf("%s %.2f\n", courses[i].name, 0.00);
			printf("Classificados\n");
			printf("Lista de espera\n");
		} else {
			while (walker != NULL) {
				last = walker;
				walker = walker->next;
			}
			walker = courses[i].vacancies;
			printf("%s %.2f\n", courses[i].name, last->student->score);
			printf("Classificados\n");
			if (walker != NULL) {
				while (walker != NULL) {
					printf("%s %.2f\n", walker->student->name, walker->student->score);
					walker = walker->next;
				}
			}
			walker = courses[i].waitingList;
			printf("Lista de espera\n");
			if (walker != NULL) {
				while (walker != NULL) {
					printf("%s %.2f\n", walker->student->name, walker->student->score);
					walker = walker->next;
				}
			}
		}
		printf("\n");
	}
}