/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _STACK_PRIVATE_H_
#define _STACK_PRIVATE_H_

/* StackNode type Definition */
typedef struct stacknode{
	Stack_Entery entry;
	struct stacknode *next;
}StackNode;



#endif