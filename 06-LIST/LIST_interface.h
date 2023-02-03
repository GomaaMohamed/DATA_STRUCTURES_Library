/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _LIST_INTERFACE_H_
#define _LIST_INTERFACE_H_
//Stack and Queue is a Special Cases of List
/* List type Definition */
typedef struct list{
	ListNode *head;
	u32 List_Size;
}List;

/* it Initialize List */
void STACK_InitializeList(List *pl);

/* 
*it Insert an Element in The List
*Pre Condition: List is Initialized and not Full
* 0 <= P <= List_Size
*/
void LIST_Insert(u32 P, List_Entery e,List *pl);

/* 
*it take an Element from The List
*Pre Condition: List is Initialized and not Empty
*/
void LIST_DeleteElement(u32 P, List_Entery e,List *pl);

/* 
*it Check if The List is FUll or Not
*Return Value: 1 if The List is Full else return 0
*/
u8 List_IsFull(List *pl);

/* 
*it Check if The List is FUll or Not 
*Return Value: 1 if The List sis Empty else return 0
*/
u8 LIST_IsEmpty(List *pl);

/* 
*it Indicate The List Size
*Return Value: Current Size Of List
*Pre Condition: List is Initialized 
*/
u32 LIST_CurrentSize(List *pl);

/* 
*it Clear The List
*Pre Condition: List is Initialized 
*/
void LIST_DestroyList(List *pl);

/* 
*it take all Elements in the List Without Destroy it them 
*Pre Condition: List is Initialized 
*/
void LIST_RetrieveElement(u32 P, List_Entery e,List *pl);

/* 
*it Replace An Element In List
*Pre Condition: List is Initialized 
*/
void LIST_ReplaceElement(u32 P, List_Entery e,List *pl);

/* 
*it take all Elements in the List Without Destroy it them 
*Pre Condition: List is Initialized 
*/
void LIST_TraverseList(List *pl,void (*pf)(List_Entry));

#endif