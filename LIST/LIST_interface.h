/*****************************************************************************
* @file:    LIST_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   List module: Array based and Linked based methods are supported
******************************************************************************/
#ifndef _LIST_INTERFACE_H
#define _LIST_INTERFACE_H

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "LIST_config.h"

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* List type Definition */
#if L_IMPLEMENTATION_METHOD == L_ARRAY_BASED
typedef struct list
{
	u32 ListSize;
	ListEntry_type Entry[MAX_LIST];
}List_type;
#elif L_IMPLEMENTATION_METHOD == L_LINKED_BASED
typedef struct listnode
{
	struct listnode *ptrNext;
	ListEntry_type Entry;
}ListNode_type;
typedef struct list
{
	ListNode_type *ptrHead;
	u32 ListSize;
}List_type;
#endif

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize list
 * @parameter1----------------> (ptrList) pointer to the list to be initialized
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant 
 */
void LIST_initializeList(List_type *ptrList);

/**
 * @brief---------------------> Insert an element in the list
 * @parameter1----------------> (Element) the element that will be inserted in the list
 * @parameter2----------------> (Position) position that the element will be inserted at
 * @parameter3----------------> (ptrList) pointer to the list that the element will be inserted inside
 * @return--------------------> None
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
void LIST_insertElement(ListEntry_type Element, u32 Position,List_type *ptrList);

/**
 * @brief---------------------> It take an element from the list and delete it
 * @parameter1----------------> (Position) position that the element deleted
 * @parameter2----------------> (ptrList) pointer to the list that the element will be deleted from
 * @return--------------------> Element that will be deleted
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
ListEntry_type LIST_deleteElement(u32 Position, List_type *ptrList);

/**
 * @brief---------------------> Check if the list is full or not
 * @parameter1----------------> (ptrList) pointer to the list be checked
 * @return--------------------> 1 if it is full else it return 0
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u8 LIST_isFull(List_type *ptrList);

/**
 * @brief---------------------> Check if the list is empty or not
 * @parameter1----------------> (ptrList) pointer the list to be checked
 * @return--------------------> 1 if it is empty else it return 0
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u8 LIST_isEmpty(List_type *ptrList);

/**
 * @brief---------------------> Get the current size of the list
 * @parameter1----------------> (ptrList) pointer to the list to get its size
 * @return--------------------> Size of the list
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u32 LIST_getCurrentSize(List_type *ptrList);

/**
 * @brief---------------------> Clear the list
 * @parameter1----------------> (ptrList) pointer to the list to be cleared
 * @return--------------------> None
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
void LIST_destroyList(List_type *ptrList);

/**
 * @brief---------------------> It take an element from the list without destroy it
 * @parameter1----------------> (Position) position that the element deleted
 * @parameter2----------------> (ptrList) pointer to the list that the element will be deleted from
 * @return--------------------> Element that will be deleted
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
ListEntry_type LIST_retrieveElement(u32 Position,List_type *ptrList);

/**
 * @brief---------------------> Replace an element from the list
 * @parameter1----------------> (Element) the element that will be replaced 
 * @parameter2----------------> (Position) position that the element will be replaced
 * @parameter3----------------> (ptrList) pointer to the list that the element will be replaced
 * @return--------------------> None
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
void LIST_replaceElement( ListEntry_type Element,u32 Position,List_type *ptrList);

/**
 * @brief---------------------> Traverse all elements of the list
 * @parameter1----------------> (ptrList) pointer to the list to be traversed
 * @parameter2----------------> (ptrFunction) pointer to the function that will be performed on the list elements
 * @return--------------------> None
 * @preconditions-------------> List is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
void LIST_traverseList(List_type *ptrList,void (*ptrFunction)(ListEntry_type));

#endif
