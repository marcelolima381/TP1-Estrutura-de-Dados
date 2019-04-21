#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "course.h"
#include "student.h"

int main() {
	int numberOfCourses;
	int numberOfStudents;

	scanf("%i %i", &numberOfCourses, &numberOfStudents);
	getchar();

	Course *courses = (Course *) malloc (numberOfCourses * sizeof(Course));
	registerCourses(numberOfCourses, courses);

	Student *students = (Student *) malloc (numberOfStudents * sizeof(Student));
	registerStudents(numberOfStudents, students);

	

	/*Student *student1 = (Student *) malloc (sizeof(Student));
	student1->name = "Marcelo";
	student1->firstOption = 0;
	student1->secondOption = 1;

	insertAtEnd(&courses[0].vacancies, student1);

	printList(courses[0].vacancies);*/

	/*int i;
	for (i = 0; i < numberOfCourses; i++) {
		printf("%s\n%i\n", courses[i].name, courses[i].numberOfVacancies);
	}*/

	return 0;
}