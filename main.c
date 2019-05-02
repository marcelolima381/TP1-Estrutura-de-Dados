#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "course.h"
#include "student.h"
#include "sisu.h"

int main() {
	int numberOfCourses;
	int numberOfStudents;

	scanf("%i %i", &numberOfCourses, &numberOfStudents);
	getchar();

	Course *courses = (Course *) malloc (numberOfCourses * sizeof(Course));
	registerCourses(numberOfCourses, courses);

	Student *students = (Student *) malloc (numberOfStudents * sizeof(Student));
	registerStudents(numberOfStudents, students);

	showSisuResult(courses, students, numberOfStudents, numberOfCourses);

	return 0;
}