//
// Created by marcelo on 20/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "utils.h"

Student* setStudent() {
	Student *student = (Student *) malloc (sizeof(Student));
	student->name = readDynamicString();
//	removeLastChar(student->name);
	scanf("%f %i %i", &student->score, &student->firstOption, &student->secondOption);
	getchar();

	return student;
}

void registerStudents(int numberOfStudents, Student *students) {
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		Student *student = setStudent();
		students[i] = *student;
		free(student);
//		printf("Nome: %s | Nota: %.2f | 1a opcao: %i | 2a opcao: %i\n", students[i].name, students[i].score, students[i].firstOption, students[i].secondOption);
	}
}