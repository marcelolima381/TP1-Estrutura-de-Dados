//
// Created by marcelo on 21/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sisu.h"
#include "course.h"
#include "student.h"

void showSisuResult(Course *courses, Student *students, int numberOfStudents) {
	int i;
	int firstOption;
	int secondOption;
	float score;

	for (i = 0; i < numberOfStudents; i++) {
		firstOption = students[i].firstOption;
		secondOption = students[i].secondOption;
		score = students[i].score;

//		Checa primeira opcao
		Node *node = courses[firstOption].vacancies;
		Node *last = NULL;
		int size = 0;
//		Pega tamanho da lista de aprovados no curso
		while (node != NULL) {
			size++;
			last = node;
			node = node->next;
		}

		if (size != 0) {
			if (size == courses[firstOption].numberOfVacancies) {
				if (last->student->score > score) {
//				TODO: implementar segunda opcao de curso
//				segundaOpcao();
					printf("segunda opcao");
				} else {
					node = courses[firstOption].vacancies;
					while (node != NULL) {
						if (node->student->score < score) {
							insertAfterNode(node->previous, &students[i]);
							last->previous->next = NULL;
//						segundaOpcao();
							printf("segunda opcao");
							break;
						}
						node = node->next;
					}
				}
			} else if (size < courses[firstOption].numberOfVacancies) {
				node = courses[firstOption].vacancies;
				while (node != NULL) {
					if (node->student->score < score) {
						printf("Dados da cabeça: %s %.2f\n", node->student->name, node->student->score);
						insertBeforeNode(&node, node, &students[i]);
						break;
					} else if (node->student->score > score && node->next == NULL) {
						insertAtEnd(&courses[firstOption].vacancies, &students[i]);
						break;
					}
					node = node->next;
				}
			} else {
				printf("PROBLEMA!\n");
			}
		} else {
			insertAtBeginning(&courses[firstOption].vacancies, &students[i]);
		}
	}

	printList(courses[0].vacancies);

}