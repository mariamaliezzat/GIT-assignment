/****************************************************************************/
/*										Student 1							*/
/* Name: Omar Ahmed Fahmy 													*/
/* Sec:  3																	*/
/* BN:	 10																	*/
/****************************************************************************/
/*										Student 2							*/
/* Name: Mariam Ali Ezzat Darwish											*/
/* Sec:  4																	*/  
/* BN: 	 9																	*/
/****************************************************************************/
/*										Student 3							*/
/* Name: Aliaa Mohamed Abdelati Bakr										*/
/* Sec:  3																	*/  
/* BN: 	 6																	*/
/****************************************************************************/

//includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "DynamicArray_interface.h"
#include "LinkedList_Interface.h"
#include "LinkedList_Private.h"

#define MAX_NAME_LENGTH     50
unsigned int number_Of_Students_list,number_Of_Students_array;
void getStudentData(students* newStudentPtr);//function for getting data of the student from user
void delay(int number_of_seconds);//delay function used for increasing resolution of the clock function

int main()
{
    printf("*************************************************\n\twelcome to our repository\n\n");
    
    unsigned char choice1,choice2,choice3;
    unsigned int i,index,middle;
    students myStudent1={"Mariam",1,1,1,1,1};

    clock_t start,stop;
    double time_calculated;
    /*Get N students*/
    printf("please enter number of students of the linked list\n");
    scanf("%d",&number_Of_Students_list);

    printf("please enter number of students of the Array\n");
    scanf("%d",&number_Of_Students_array);
    /*Create Linked List*/
    //getStudentData(&myStudent1);
    printf("creating list of %d students \n",number_Of_Students_list);
    for(i=0;i<number_Of_Students_list;i++)
    {
        //getStudentData(&myStudent1);
        Add_Student (i,myStudent1);
    }
    printf ("List created\n");
    //Print_List();


    /*Create Dynamic Array*/
    printf("creating Dynamic Array of %d students \n",number_Of_Students_array);
    for(i=1;i<=number_Of_Students_array;i++)
    {
        //getStudentData(&myStudent1);
        void_DynArr_insertMiddle(&myStudent1,i);
    }
    printf (" Dynamic Array created\n");
    //void_DynArr_printArr();
	
    while(1)
    {
        printf("enter your choice \n1 Insertion \n2 Calculation (time and size)\n3 exit\n");
        scanf("%d",&choice1);
        switch(choice1)
        {
        case 1:
            printf("enter your choice \n1 Insertion in LinkedList \n2 Insertion in Dynamic Array\n");
            scanf("%d",&choice2);
            switch(choice2)
            {
            case 1:
                /*Insertion in linked list*/
                number_Of_Students_list++;
                printf("Enter Index\n");
                scanf("%d",&index);
                Add_Student (index,myStudent1);
                //Print_List();
                break;
            case 2:
                /*Insertion in Dynamic Array*/
                number_Of_Students_array++;
                printf("Enter Index\n");
                scanf("%d",&index);
                void_DynArr_insertMiddle(&myStudent1,index);
                //void_DynArr_printArr();
                break;
            default:
                return 0;
                break;
            }
            break;
            case 2:
                printf("choose for calculations\n1 calculate time for insertion at beginning \n2 calculate time for insertion at middle \n3 calculate time for insertion at last\n4 calculate the size taken by structure\n5 calculate the size taken by the node of the linked list\n");
                scanf("%d",&choice3);
                switch(choice3)
                {
                case 1:
                    /*execution time for insertion at beginning in linked list*/
                    start= clock();
                    Add_Student (0,myStudent1);
                    delay(5);
                    stop = clock();
                    time_calculated = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at beginning in linked list(ms): %f \n",time_calculated-5000);
                    number_Of_Students_list++;


                    /*execution time for insertion at beginning in Dynamic Array*/
                    start= clock();
                    void_DynArr_insertMiddle(&myStudent1,1);
                    delay(5);
                    stop= clock();
                    time_calculated= (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at beginning in array(ms): %f \n", time_calculated-5000);
                    number_Of_Students_array++;
                    break;
                case 2:
                    /*calculating middle position*/
                    middle=number_Of_Students_list/2;
                    /*execution time for insertion at middle in Dynamic Array*/
                    start= clock();
                    Add_Student (middle,myStudent1);
                    delay(5);
                    stop= clock();
                    time_calculated = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at middle in linked list(ms): %f \n", time_calculated-5000);
                    number_Of_Students_list++;

                    /*calculating middle position*/
                    middle=number_Of_Students_array/2; 
                    /*execution time for insertion at middle in Dynamic Array*/
                    start= clock();
                    void_DynArr_insertMiddle(&myStudent1,middle);
                    delay(5);
                    stop= clock();
                    time_calculated = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at middle in array(ms): %f \n", time_calculated-5000);
                    number_Of_Students_array++; 

                    break;
                case 3:
                    /*execution time for insertion at last in linked list*/

                    start= clock();
                    Add_Student (number_Of_Students_list-1,myStudent1);
                    delay(5);
                    stop= clock();
                    time_calculated = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at the end in linked list(ms): %f \n",time_calculated-5000);
                    number_Of_Students_list++;               
					
                    /*execution time for insertion at last in Dynamic Array*/
                    start= clock();
                    void_DynArr_insertMiddle(&myStudent1,number_Of_Students_array);
                    delay(5);
                    stop= clock();
                    time_calculated= (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at the end in array(ms): %f \n", time_calculated-5000);
                    number_Of_Students_array++;
                    break;
                case 4:

                        printf("size taken by the structure %d\n",sizeof(students));
                    break;
                case 5:

                        printf("size taken by the node of the linked list %d\n",sizeof(nodes));
                    break;
                default:
                    return 0;
                    break;
                }

                break;
                case 3:
                    return 0;
                    break;
                default:
                    return 0;
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
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
