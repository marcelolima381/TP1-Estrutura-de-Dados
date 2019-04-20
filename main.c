#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "course.h"



int main() {
	int numberOfCourses;
	int numberOfStudents;

	scanf("%i %i", &numberOfCourses, &numberOfStudents);
	getchar();

	Course *courses = (Course *) malloc (numberOfCourses * sizeof(Course));
	registerCourses(numberOfCourses, courses);

	return 0;
}