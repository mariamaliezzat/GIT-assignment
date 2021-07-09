#include <stdio.h>
#include "struct.h"
#include "LinkedList_Interface.h"
#include <stdlib.h>

#define NUM_OF_STUDENTS 	5
#define MAX_NAME_LENGTH 	50

void getStudentData(students* newStudentPtr);
#include "DynamicArray_interface.h"
int main()
{
    printf("*************************************************\n\twelcome to our repository\n\n");
	/**************** Linked list consisting of 3 students test *****************************/
	int choice, index;
	students myStudent;
	
	while (1)
	{
		printf ("\n\n1. Add a student\n");
		printf ("2. Print the list\n");
		printf ("Choose <1 - 2>: ");
		scanf ("%d", &choice);
		
		while (choice != 1 && choice != 2)
		{
			printf ("\nInvalid choice\n\n");
			printf ("1. Add a student\n");
			printf ("2. Print the list\n");
			printf ("Choose <1 - 2>: ");
			scanf ("%d", &choice);
		}
		
		switch (choice)
		{
			case 1:
			getStudentData(&myStudent);
			printf ("Enter the index (position) to store the new node at: ");
			scanf ("%d", &index);
			Add_Student(index, myStudent);
			break;
			
			case 2:
			Print_List();
			break;
		}
	}
}
	
void getStudentData(students* newStudentPtr)
{
    students newStudent;
    unsigned char nameLength;
	printf ("Enter the number of characters for the student's name (%d max): ", MAX_NAME_LENGTH);
	scanf ("%d", &nameLength);
	getchar();

	while (nameLength > MAX_NAME_LENGTH)
	{
		printf ("Invalid name length!\n");
		printf ("Enter the number of characters for the student's name (%d max): ", MAX_NAME_LENGTH);
		scanf ("%d", &nameLength);
		getchar();
	}

	/* Allocate memory for the name + the null character */
	newStudent.name = (char*) malloc( sizeof(char) * nameLength + sizeof(char) ); 
	printf ("Enter the student's name: ");
	fgets (newStudent.name, nameLength + 1, stdin);
	printf ("Enter the student's ID: ");
	scanf ("%d", &(newStudent.ID) );
	printf ("Enter the student's day of birth: ");
	scanf ("%d", &(newStudent.birth_day) );
	printf ("Enter the student's month of birth: ");
	scanf ("%d", &(newStudent.birth_month) );
	printf ("Enter the student's year of birth: ");
	scanf ("%d", &(newStudent.birth_year) );
	printf ("Enter the student's score last year: ");
	scanf ("%d", &(newStudent.score) );
	*newStudentPtr = newStudent;
}
