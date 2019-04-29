//
// Created by marcelo on 21/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "linkedList.h"

void secondOption(Student *student) {
	printf("segunda opcao\n");
	printf("Desclassificado da primeira opcao: %s\n", student->name);
}

int checkListEmpty(int size) {
    return size == 0 ? 1 : 0;
}

int courseIsFull(int size, int numberOfVacancies) {
	return size == numberOfVacancies ? 1 : 0;
}

void insertAtFullCourse(Course *course, Node *last, Node *node, Student *student, float score) {
	node = course->vacancies;
	while (node != NULL) {
		if (node->student->score < score) {
			insertAfterNode(node->previous, student);
			Student *disclassifiedStudent = last->student;
			last->previous->next = NULL;
			secondOption(disclassifiedStudent);
			break;
		}
		node = node->next;
	}
}

void insertAtHungryCourse(Course *course, Node *node, Student *student, float score) {
	node = course->vacancies;
	while (node != NULL) {
		if (node->student->score < score) {
			if (node->previous != NULL) {
				insertBeforePreviousNull(node, student);
			} else {
				insertBeforeNode(node, student);
			}
			course->vacancies = node;
			break;
		} else if (node->student->score > score && node->next == NULL) {
			insertAtEnd(&course->vacancies, student);
			break;
		}
		node = node->next;
	}
}

void manageCourseVacancies(Course *course, Node *last, Node *node, Student *student, int size, float score) {
    if (courseIsFull(size, course->numberOfVacancies)) {
        Student *candidate = (Student *) malloc (sizeof(Student));
        candidate = student;
		last->student->score > score ? secondOption(candidate)
									 : insertAtFullCourse(course, last, node, student, score);
    } else {
    	insertAtHungryCourse(course, node, student, score);
    }
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

void showSisuResult(Course *courses, Student *students, int numberOfStudents) {
	int i;
	int firstOption;
	int secondOption;
	float score;

	for (i = 0; i < numberOfStudents; i++) {
		firstOption = students[i].firstOption;
		secondOption = students[i].secondOption;
		score = students[i].score;

		Node *node = courses[firstOption].vacancies;
		Node *last;
		int size = getListSize(node, &last);

        checkListEmpty(size) ? insertAtBeginning(&courses[firstOption].vacancies, &students[i])
							 : manageCourseVacancies(&courses[firstOption], last, node, &students[i], size, score);

		rewindList(&courses[firstOption], last);
	}

	printList(courses[0].vacancies);

}