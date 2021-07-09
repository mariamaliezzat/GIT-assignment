#ifndef LINKEDLIST_PRIVATE_H_INCLUDED
#define LINKEDLIST_PRIVATE_H_INCLUDED

/************************************************************************************/
/* 			    				  NODES-RELATED DATA								*/
/************************************************************************************/
typedef struct nodes_t nodes;

struct nodes_t
{
	students studentInfo;
	nodes *next;
};

nodes* head = NULL;

unsigned int numberOfStudents;
/************************************************************************************/



/************************************************************************************/
/* 				   					USEFUL MACROS					                */
/************************************************************************************/
#define ZERO 				0
#define ONE	 				1
/************************************************************************************/



#endif // LINKEDLIST_PRIVATE_H_INCLUDED
