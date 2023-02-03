/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _LIST_PRIVATE_H_
#define _LIST_PRIVATE_H_

typedef struct listnode{
	struct listnode *next;
	List_Entry entry;
}ListNode;


#endif