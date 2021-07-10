/******************************************************************************
 *
 * File Name:   DynamicArray_program.c
 *
 * Description: functions implementation used for the dynamic array
 *
 * Date:        4/14/2021
 *
 ******************************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include "struct.h"
 #include "DynamicArray_interface.h"
 
 int num_students=0;
 students* first_student;
 
 
 /*
 void void_DynArr_insertBeginning(void)
  {
	students* temp;  int nameLength; char* name;
	num_students++;                                                         //increasing number of the students
	  
	students newStd;                                                        //creat new student
	
	printf("Enter the number of characters for the name (max 50): ");        //getting the information of the student
	scanf("%d",&nameLength);
	getchar();
	if(nameLength<= 50)
	{
		printf("Please enter the student's name\n"); 
		name=(char*)malloc(sizeof(char)+sizeof(char)*nameLength);
		fgets(name, nameLength+1, stdin);
		newStd.name=name;
	}
	else {printf("invalid name length"); }
	                      
	
	printf("Please enter the student's ID\n");
	scanf("%d",&newStd.ID);
	printf("Please enter the student's birth day\n");
	scanf("%d",&newStd.birth_day);
	printf("Please enter the student's birth month\n");
	scanf("%d",&newStd.birth_month);
	printf("Please enter the student's birth year\n");
	scanf("%d",&newStd.birth_year);
	printf("Please enter the student's score\n");
	scanf("%d",&newStd.score);
	
	if(num_students==1)                                                   //in case of the first student
	{
		first_student=(students*)malloc(sizeof(students));               //reserve memory for the new student
		*first_student=newStd;                                            //put the information of the new student in the reserved memory 
		
	}
	else
	{
		first_student=(students*)realloc(first_student, num_students * sizeof(students));       //increasing the size of the array 
		
		temp=first_student+num_students-1;
		
		for(int i=0; i < num_students; i++)
		{
			*temp=*(temp-1);                                                                     //shift the array into right to put the new student at the beginning 
			temp--;
		}
		*first_student=newStd;    	                                                        	//put the information of the new student in the reserved memory
	
	}
	
  }*/
  
   void void_DynArr_insertMiddle(students* newStd,unsigned int index)
 {
	students* temp;
	students* ptrNewStd;
	num_students++;                                                         //increasing number of the students
	  

	
	first_student=(students*)realloc(first_student, num_students * sizeof(students));            //increasing the size of the array 
	ptrNewStd=first_student+index-1;                                                             //pointer to the required place
	temp=first_student+num_students-1;                                                           //pointer to the last place
		
	if (index==num_students)
	{
		*temp=*newStd;
	}
	else
	{
		for(int i=0; (i < num_students)&&(temp != ptrNewStd); i++)
		{
			temp=(temp-1);                                                                     //shift the array into right to put the new student at the beginning 
			temp--;
		}
		*ptrNewStd=*newStd;	
	}
	                                                                          //assign the information of the new student in the reserved memory
 }
 
 
/* void void_DynArr_insertEnd(void)
 {
	 students* temp;          int nameLength; char* name;
	num_students++;                                                       //increasing number of the students
	  
	students newStd;                                                      //creat new student
	
	printf("Enter the number of characters for the name (max 50): ");        //getting the information of the student
	scanf("%d",&nameLength);
	getchar();
	if(nameLength<= 50)
	{
		printf("Please enter the student's name\n"); 
		name=(char*)malloc(sizeof(char)+sizeof(char)*nameLength);
		fgets(name, nameLength+1, stdin);
		newStd.name=name;
	}
	else {printf("invalid name length"); }
	
	printf("Please enter the student's ID\n");
	scanf("%d",&newStd.ID);
	printf("Please enter the student's birth day\n");
	scanf("%d",&newStd.birth_day);
	printf("Please enter the student's birth month\n");
	scanf("%d",&newStd.birth_month);
	printf("Please enter the student's birth year\n");
	scanf("%d",&newStd.birth_year);
	printf("Please enter the student's score\n");
	scanf("%d",&newStd.score);
	
	first_student=(students*)realloc(first_student, num_students * sizeof(students));       //increasing the size of the array 
	
	temp=first_student+num_students-1;                                                       //pointer to the last student
	*temp=newStd;                                                                          //assign the information of the new student in the reserved memory
		
	
 }
  */
   void void_DynArr_printArr(void)
  {
	  students* temp=first_student;
	  for(int i=0; i<num_students; i++)
	  {
		  printf("name: %s\n",(*temp).name);
		  printf("%d\n",(*temp).ID);
		  printf("%d\n",(*temp).birth_day);
		  printf("%d\n",(*temp).birth_month);
		  printf("%d\n",(*temp).birth_year);
		  printf("%d\n",(*temp).score);
		  temp++;
	  }
  }