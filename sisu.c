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

void insertAtFullCourse(Course *courses, Node *last, Node *node, Student *student, float score, int option) {
	node = courses[option].vacancies;
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

void insertAtHungryCourse(Course *courses, Node *node, Student *student, float score, int option) {
	node = courses[option].vacancies;
	while (node != NULL) {
		if (node->student->score < score) {
			if (node->previous != NULL) {
				insertBeforePreviousNull(node, student);
			} else {
				insertBeforeNode(node, student);
			}
			courses[option].vacancies = node;
			break;
		} else if (node->student->score > score && node->next == NULL) {
			insertAtEnd(&courses[option].vacancies, student);
			break;
		}
		node = node->next;
	}
}

void manageCourseVacancies(Course *courses, Node *last, Node *node, Student *student, int size, float score, int option) {
    if (courseIsFull(size, courses[option].numberOfVacancies)) {
        Student *candidate;
        candidate = student;
		if (last->student->score > score) {

            secondOption(candidate);
		} else {
            insertAtFullCourse(courses, last, node, student, score, option);
        }
    } else {
    	insertAtHungryCourse(courses, node, student, score, option);
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

        if (checkListEmpty(size)) {
            insertAtBeginning(&courses[firstOption].vacancies, &students[i]);
        } else {
            manageCourseVacancies(courses, last, node, &students[i], size, score, firstOption);
        }

		rewindList(&courses[firstOption], last);
	}

	printList(courses[0].vacancies);

}