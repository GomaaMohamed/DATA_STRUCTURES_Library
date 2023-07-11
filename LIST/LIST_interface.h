/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _LIST_INTERFACE_H_
#define _LIST_INTERFACE_H_

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "LIST_config.h"


/* ==================================================================== */
/* ======================= public data types ========================== */
/* ==================================================================== */

/* Stack type Definition */
#if L_IMPLEMENTATION_METHOD == L_ARRAY_BASED
typedef struct list{
	u32 List_Size;
	List_Entry entry[MAX_LIST];
}List;
#elif L_IMPLEMENTATION_METHOD == L_LINKED_BASED
typedef struct listnode{
	struct listnode *next;
	List_Entry entry;
}ListNode;
typedef struct list{
	ListNode *head;
	u32 List_Size;
}List;
#endif

/* ==================================================================== */
/* ==================== public functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief   initialize list
 * @param   pl pointer to the list that will be initialized
 * @return  None
 * @example
 *          ex:   List l;
 *                LIST_InitializeList(&l);
 */ 
void LIST_InitializeList(List *pl);

/**
 * @brief   insert an element in the list
 * @param   e the element that will be inserted in the list
 * @param   pl pointer to the list that the element will be inserted inside
 * @param   P position that the element will be inserted at
 * @return  none
 * @pre     list is initialized and not full
 * @example
 *          ex:   List l;
 *                LIST_Insert(&l);
 */
void LIST_Insert(u32 P, List_Entry e,List *pl);

/**
 * @brief   it take an element from the list
 * @param   P position that the element will be taken from
 * @param   pl pointer to the list that the element will be taken from 
 * @return  the taken element
 * @pre     list is initialized and not empty
 * @example
 *          ex:   List l;
 *                List_Entry ret = LIST_DeleteElement(5,l);
 */ 
List_Entry LIST_DeleteElement(u32 P, List *pl);

/**
 * @brief   check if the list is full or not
 * @return  return 1 if the list is full else it returns 0
 * @pre     list is initialized 
 * @example
 *          ex:   u8 check;
 *                check = List_IsFull(&l);
 */ 
u8 LIST_IsFull(List *pl);

/**
 * @brief   Check if the list is empty or not
 * @return  1 if the list is empty else it returns 0
 * @pre     list is initialized 
 * @example
 *          ex:   u8 check;
 *               check = LIST_IsEmpty(&l);
 */ 
u8 LIST_IsEmpty(List *pl);

/**
 * @brief   get the current size of the list
 * @param   pl pointer to the list that its size will be taken 
 * @return  list size
 * @pre     list is initialized 
 * @example
 *          ex:   u32 size;
 *                size = LIST_CurrentSize(&l);
 */ 
u32 LIST_CurrentSize(List *pl);

/**
 * @brief   clear the list
 * @param   pl pointer to the list that will be cleared 
 * @return  none
 * @pre     list is initialized 
 * @example
 *          ex:   LIST_ClearList(&l);
 */
void LIST_DestroyList(List *pl);

/* 
*it take all Elements in the List Without Destroy it them 
*Pre Condition: List is Initialized 
*/
/**
 * @brief   it take an element from the list wihout delete it
 * @param   P position that the element will be taken from
 * @param   pl pointer to the list that the element will be taken from 
 * @return  the taken element
 * @pre     list is initialized and not empty
 * @example
 *          ex:   List l;
 *                List_Entry ret = LIST_DeleteElement(5,l);
 */ 
List_Entry LIST_RetrieveElement(u32 P,List *pl);

/**
 * @brief   replace an element from the list
 * @param   pl pointer to the list 
 * @param   e the new element
 * @param   P position of the element
 * @return  none
 * @pre     list is initialized 
 * @example
 *          ex:   list l;  
 *                LIST_ReplaceElement(5,7,&l);
 */ 
void LIST_ReplaceElement(u32 P, List_Entry e,List *pl);

/**
 * @brief   traverse all elements of the list
 * @param   pl pointer to the list that will be traversed
 * @param   pf pointer to the function that will be performed on the list elements
 * @return  none
 * @pre     list is initialized 
 * @example
 *          ex:   List l;  
 *                List_TraverseList(&l,func);
 */ 
void LIST_TraverseList(List *pl,void (*pf)(List_Entry));

#endif
