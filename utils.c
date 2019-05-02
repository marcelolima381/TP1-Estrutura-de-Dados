//
// Created by marcelo on 20/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "datatype.h"
#include "sisu.h"
#include "linkedList.h"

char *readDynamicString() {
	char *str;
	char c;
	int strLength = 0;
	str = (char *) malloc(INITIAL_SIZE * sizeof(char));

	while ((c = getchar()) != '\n' && c != EOF) {
//		if (isalpha((unsigned char) c) || c == ' ') {
			str[strLength] = c;
			strLength++;
			str = (char *) realloc(str, INITIAL_SIZE + strLength);
//		}
	}
	if (strlen(str) != strLength) {
		str[strLength] = '\0';
	}

	return str;
}
void secondOption(Course* courses, Node **node, Student *student) {
	Node *last;
	int size = getListSize(*node, &last);

	if (checkListEmpty(size)) {
		insertAtBeginning(&courses[student->secondOption].vacancies, student);
	} else {
		manageCourseVacancies(courses, last, *node, student, size, student->secondOption);
	}
}


void removeLastChar(char *str) {
	int i = 0;
	for (i = 0; i < strlen(str); i++) {
		printf("Caractere da string dinamica: %c\n", str[i]);
	}
	str[strlen(str) - 1] = '\0';
}