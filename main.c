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

unsigned int number_Of_Students_list,number_Of_Students_array;
typedef struct {
    unsigned int ID;
    unsigned int birth_day;
    unsigned int birth_month;
    unsigned int birth_year;
    signed int score;
    char* name;
}students;
typedef struct nodes_t nodes;

struct nodes_t
{
    students studentInfo;
    nodes *next;
};
#define ZERO                0
#define ONE                 1
#define MAX_NAME_LENGTH     50
students* first_student;
nodes* head = NULL;
nodes* tail = NULL;

void Add_Student (int index, students* newStudentData);
void void_DynArr_insertMiddle(students* newStd,unsigned int index);
void Print_List(void);
void void_DynArr_printArr(void);

void Add_Student (int index, students* newStudentData)
{

    /* If an invalid index was entered */
    if (index > number_Of_Students_list || index < ZERO)
    {
        printf ("\nInvalid Index!\n");
        return;
    }
    else
    {
        /* Dynamically allocate a new node in the list */
        nodes* newNode = (nodes*) malloc ( sizeof(nodes) );
        /* Assign the student's info to the new node */
        newNode -> studentInfo = *newStudentData;
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
		else if (index == number_Of_Students_list)
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
        number_Of_Students_list++;
    }
}


void void_DynArr_insertMiddle(students* newStd,unsigned int index)
{
    students* temp;
    students* ptrNewStd;
    number_Of_Students_array++;                                                         //increasing number of the students



    first_student=(students*)realloc(first_student, number_Of_Students_array * sizeof(students));            //increasing the size of the array
    ptrNewStd=first_student+index-1;                                                             //pointer to the required place
    temp=first_student+number_Of_Students_array-1;                                                           //pointer to the last place
    if (index== number_Of_Students_array)
    {
        *temp=*newStd;
    }
    else
    {
        for(int i=0; (i < number_Of_Students_array)&&(temp != ptrNewStd); i++)
        {
            *temp=*(temp-1);                                                                     //shift the array into right to put the new student at the beginning
            temp--;
        }
        *ptrNewStd=*newStd;
    }
}

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

    printf ("NULL\n\nNumber of students = %d", number_Of_Students_list);
}

void void_DynArr_printArr(void)
{
    students* temp=first_student;
    for(int i=0; i<number_Of_Students_array; i++)
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

void getStudentData(students* newStudentPtr);//function for getting data of the student from user
void delay(int number_of_seconds);//delay function used for increasing resolution of the clock function

int main()
{
    printf("*************************************************\n\twelcome to our repository\n\n");
		unsigned char choice1, choice2, choice3;
		unsigned int index, middle;
		students myStudent1= {"Mariam", 1, 1, 1, 1, 1};
		unsigned int number_Of_Students_list1, number_Of_Students_array1;
		clock_t start, stop;
		double time_calculated;
        /*Get N students*/
        printf("please enter number of students of the linked list: ");
        scanf("%d",&number_Of_Students_list1);

        printf("please enter number of students of the Array: ");
        scanf("%d",&number_Of_Students_array1);

        for(int i = 0; i < number_Of_Students_list1; i++)
        {
            Add_Student (i,&myStudent1);
        }
    
        printf ("\nList created\n");

        for(int i = 1; i <= number_Of_Students_array1; i++)
        {
            void_DynArr_insertMiddle(&myStudent1,i);
        }
        printf (" Dynamic Array created\n\n");
	
        while(1)
        {
            printf("\nenter your choice \n1 Insertion \n2 Calculation (time and size)\n3 Print list and array\n4 return\n");
            scanf("%d",&choice1);
            switch(choice1)
            {
                case 1:
                printf("\nenter your choice \n1 Insertion in LinkedList \n2 Insertion in Dynamic Array\n");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1:
                    /*Insertion in linked list*/
                    printf("Enter Index\n");
                    scanf("%d",&index);
                    Add_Student (index,&myStudent1);
                    break;
                    case 2:
                    /*Insertion in Dynamic Array*/
                printf("Enter Index\n");
                scanf("%d",&index);
                void_DynArr_insertMiddle(&myStudent1,index);
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
                    Add_Student (1,&myStudent1);
                    // delay(5);
                    stop= clock();
                    time_calculated = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at beginning in linked list(ms): %f \n",time_calculated);
                    //  number_Of_Students_list++;


                    /*execution time for insertion at beginning in Dynamic Array*/
                    start= clock();
                    void_DynArr_insertMiddle(&myStudent1,1);
                    //delay(5);
                    stop= clock();
                    time_calculated= (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at beginning in array(ms): %f \n", time_calculated);
                    //number_Of_Students_array++;
                    break;
                case 2:
               
					/*calculating middle position*/
                    middle=number_Of_Students_list/2;
                    /*execution time for insertion at middle in Dynamic Array*/
                    start= clock();
                    Add_Student (middle,&myStudent1);
                    //delay(5);
                    stop= clock();
                    time_calculated = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at middle in linked list(ms): %f \n", time_calculated);
                    //number_Of_Students_list++;

                    /*calculating middle position*/
                    middle=number_Of_Students_array/2;
                    /*execution time for insertion at middle in Dynamic Array*/
                    start= clock();
                    void_DynArr_insertMiddle(&myStudent1,middle);
                    //delay(5);
                    stop= clock();
                    time_calculated = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at middle in array(ms): %f \n", time_calculated);
                    //number_Of_Students_array++;

                    break;
                case 3:
                    /*execution time for insertion at last in linked list*/

                    start= clock();
                    Add_Student (number_Of_Students_list,&myStudent1);
                    //delay(5);
                    stop= clock();
                    time_calculated = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at last in linked list(ms): %f \n",time_calculated);
                    //number_Of_Students_list++;
                    /*execution time for insertion at last in Dynamic Array*/

                    start= clock();
                    void_DynArr_insertMiddle(&myStudent1,number_Of_Students_array);
                    //delay(5);
                    stop= clock();
                    time_calculated= (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
                    printf("execution time for insertion at last in array(ms): %f \n", time_calculated);
                    //number_Of_Students_array++;
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
				printf("\n***************** PRINTING LINKED LIST ********************\n\n");
				Print_List();
				printf ("\n\n");
				printf("\n***************** PRINTING ARRAY ********************\n\n");
				void_DynArr_printArr();
                    break;
					
					case 4:
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
