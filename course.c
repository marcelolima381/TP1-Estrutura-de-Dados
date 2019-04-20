//
// Created by marcelo on 19/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"

void removeLastChar(char *str) {
	str[strlen(str)-1] = '\0';
}

char* readDynamicString() {
	char *str;
	int strLength = 0;
	str = (char *) malloc (INITIAL_SIZE * sizeof(char));

	while ((str[strLength] = getchar()) != '\n') {
		strLength++;
		str = (char *) realloc (str, INITIAL_SIZE + strLength);
	}

	return str;
}

char* setCourseName() {
	char *name;

	name = readDynamicString();
	removeLastChar(name);

	return name;
}

int setNumberOfVacancies() {
	int numberOfVacancies;

	scanf("%i", &numberOfVacancies);
	getchar();

	return numberOfVacancies;
}

Course registerCourse() {
	Course *course = (Course *) malloc (sizeof(Course));
	char *name;
	int numberOfVacancies;

	name = setCourseName();
	numberOfVacancies = setNumberOfVacancies();

	course->name = (char *) malloc ((INITIAL_SIZE + strlen(name)) * sizeof(char));
	strcpy(course->name, name);
	course->numberOfVacancies = numberOfVacancies;
	free(name);

	return *course;
}

void registerCourses(int numberOfCourses, Course *courses) {
	int i;
	for (i = 0; i < numberOfCourses; i++) {
		courses[i] = registerCourse();
	}
}