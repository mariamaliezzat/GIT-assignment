#ifndef LINKEDLIST_INTERFACE_H_INCLUDED
#define LINKEDLIST_INTERFACE_H_INCLUDED

/************************************************************************************/
/* 								FUNCTIONS PROTOTYPE					 				*/
/************************************************************************************/


/************************************************************************************/
/* Description: adds a new student node at a user-chosen index						*/
/*																					*/
/* Input      : index - newStudentData                                              */
/*																					*/
/* Output     : nothing		                                                        */
/************************************************************************************/
extern void Add_Student (int index, students newStudentData);
/************************************************************************************/

/************************************************************************************/
/* Description: prints the details of the whole list. That is, the details of each  */
/* student, a visual representation of the list, and the total number of students.  */
/*																					*/
/* Input      : nothing  		                                                    */
/*																					*/
/* Output     : nothing		                                                        */
/************************************************************************************/
extern void Print_List(void);
/************************************************************************************/

#endif // LINKEDLIST_INTERFACE_H_INCLUDED
