#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "LinkedList_Private.h"
unsigned int numberOfStudents=0;
/************************************************************************************/
/* 						  PUBLIC FUNCTIONS IMPLEMENTATION   						*/
/************************************************************************************/
nodes* head = NULL;
nodes* tail = NULL;
void Add_Student (int index, students newStudentData)
{
	/* If an invalid index was entered */
	if (index > numberOfStudents || index < ZERO)
	{
		printf ("\nInvalid Index!\n");
		return;
	}
	else
	{
		/* Dynamically allocate a new node in the list */
		nodes* newNode = (nodes*) malloc ( sizeof(nodes) );
		/* Assign the student's info to the new node */		
		newNode -> studentInfo = newStudentData; 
		/* If the list was empty */
		if (head == NULL)
		{
			newNode -> next = NULL;
			head = newNode;
			tail = newNode;
		}
		/* If the new node is to be added at the front of the list */
		else if (index == ZERO)
		{
			newNode -> next = head;
			head = newNode;
		}
		/* If the new node is to be added at the end of the list */
		else if (index == numberOfStudents)
		{
			newNode -> next = NULL;
			tail -> next = newNode;
			tail = newNode;
		}
		/* For any arbitrary index in the list */
		else
		{
			nodes* temp = head;
		
			/* Make temp point to the node just before the required position */
			for (int counter = ZERO; counter < index - ONE; counter++)
			{
				temp = temp -> next;
			}
		
			newNode -> next = temp -> next;
			temp -> next = newNode;
		}
		numberOfStudents++;
	}
}
	

/************************************************************************************/

void Print_List(void)
{
    printf ("\n");
	nodes* temp = head;
	
	for (unsigned int counter = ONE; temp != NULL; counter++)
	{
		printf ("\t\tSTUDENT %d\n", counter);
		printf ("Name = %s", temp -> studentInfo.name);
		printf ("ID = %d\n", temp -> studentInfo.ID );
		printf ("Birth day = %d\n", temp -> studentInfo.birth_day );
		printf ("Birth month = %d\n", temp -> studentInfo.birth_month );
		printf ("Birth year = %d\n", temp -> studentInfo.birth_year );
		printf ("Score = %d\n\n\n", temp -> studentInfo.score );
		temp = temp -> next;
	}
	
	temp = head;
	printf ("head\n |\n v\n");
	
	for (unsigned int counter = ONE; temp != NULL; counter++)
	{
		printf ("%s |\n v\n", temp -> studentInfo.name);
		temp = temp -> next;
	}
	
	printf ("NULL\n\nNumber of students = %d", numberOfStudents);
}