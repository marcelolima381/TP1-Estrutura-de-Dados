//
// Created by marcelo on 21/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "linkedList.h"

void secondOption(Course* courses, Node **node, Student *student) {
	insertAtBeginning(node, student);
}

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

void insertAtHungryCourse(Course *courses, Node *node, Student *student, int option) {
//	node = courses[option].vacancies;
	while (node != NULL) {
		if (node->student->score < student->score) {
			if (node->previous != NULL) {
				insertBeforePreviousNull(node, student);
			} else {
				insertBeforeNode(node, student);
			}
			courses[option].vacancies = node;
			break;
		} else if (node->student->score > student->score && node->next == NULL) {
			insertAtEnd(&courses[option].vacancies, student);
			break;
		}
		node = node->next;
	}
}

void insertAtWaitingList(Course *courses, Student *student, int option) {
	Node *lastWaitingList;
	int size = getListSize(courses[option].waitingList, &lastWaitingList);
	if (checkListEmpty(size)) {
		insertAtBeginning(&courses[option].waitingList, student);
	} else {
		insertAtHungryCourse(courses,
							 courses[option].waitingList,
							 student,
							 option);
	}
}

void insertAtFullCourse(Course *courses, Node *last, Node *node, Student *student, int option) {
//	node = courses[option].vacancies;
	while (node != NULL) {
		if (node->student->score < student->score) {
			insertAfterNode(node->previous, student);
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
		if (last->student->score > student->score && option != student->secondOption) {
			insertAtWaitingList(courses, student, option);
//			secondOption(student);
			printf("LALALALALLALALALALLALALALALALALALLALALALALLALALALALALALALLALALALALLALALALALALALALLALALALALLALALA\n");
		} else {
			insertAtFullCourse(courses, last, node, student, option);
		}
	} else {
		insertAtHungryCourse(courses, node, student, option);
	}
}

void showSisuResult(Course *courses, Student *students, int numberOfStudents) {
	int i;
	int firstOption;
	int secondOption;

	for (i = 0; i < numberOfStudents; i++) {
		firstOption = students[i].firstOption;
		secondOption = students[i].secondOption;

		Node *node = courses[firstOption].vacancies;
		Node *last;
		int size = getListSize(node, &last);

		if (checkListEmpty(size)) {
			insertAtBeginning(&courses[firstOption].vacancies, &students[i]);
		} else {
			manageCourseVacancies(courses, last, node, &students[i], size, firstOption);
		}

		rewindList(&courses[firstOption], last);
	}
	printf("Curso: %s\n", courses[0].name);
	printList(courses[0].vacancies);
	printf("----------------------\n");
	printList(courses[0].waitingList);
	printf("**********************\n");
	printf("**********************\n");
	printf("Curso: %s\n", courses[1].name);
	printList(courses[1].vacancies);
	printf("----------------------\n");
	printList(courses[1].waitingList);
}