/*****************************************************************************
* @file:    LIST_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   List module: Array based and Linked based methods are supported
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */ 

#include  "stdlib.h"
#include  "LIST_private.h"
#include  "LIST_interface.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Array based implementations
#if L_IMPLEMENTATION_METHOD == L_ARRAY_BASED

// Function to initialize a list
void LIST_initializeList(List_type *ptrList)
{
	// Size of list equal 0 at beginning
	ptrList->ListSize = 0;
}

// Function to insert an element
void LIST_insertElement(ListEntry_type Element, u32 Position,List_type *ptrList)
{
	// Check boundries
	if (ptrList->ListSize == 0)
	{
		ptrList->Entry[Position] = Element;
	}
	else
	{
		// Loop counter
		u32 i;
		// Determine the position
		for(i=ptrList->ListSize-1;i >= Position;i--)
		{
			ptrList->Entry[i+1] = ptrList->Entry[i];
		}
		// Assign value
		ptrList->Entry[Position] = Element;
	}
	// Increase size by one
	ptrList->ListSize++;
}

// Function to get an element from the list
ListEntry_type LIST_deleteElement(u32 Position, List_type *ptrList)
{    
	// Temp variable
    ListEntry_type Temp = ptrList->Entry[Position];
	// Counter
	u32 i;
	// Determine the position
	for(i=Position+1;i <= ptrList->ListSize-1 ;i++)
	{
		ptrList->Entry[i-1] = ptrList->Entry[i];
	}
	// Decrement size by 1
	ptrList->ListSize--;
	return Temp;
}

// Function to check if the list is full
u8 LIST_isFull(List_type *ptrList)
{
	return (ptrList->ListSize == MAX_LIST);
}

// Function to check if the list is empty
u8 LIST_isEmpty(List_type *ptrList)
{
	return !ptrList->ListSize;
}

// Function to get the size of list
u32 LIST_getCurrentSize(List_type *ptrList)
{
	return ptrList->ListSize;
}

// Function to destroy list
void LIST_destroyList(List_type *ptrList)
{
	ptrList->ListSize = 0;
}

// Function to retrieve an element
ListEntry_type LIST_retrieveElement(u32 Position,List_type *ptrList)
{
	return ptrList->Entry[Position];
}

// Function to replace an element
void LIST_replaceElement( ListEntry_type Element,u32 Position,List_type *ptrList)
{
	ptrList->Entry[Position] = Element ;
}

// Function to traverse list
void LIST_traverseList(List_type *ptrList,void (*ptrFunction)(ListEntry_type))
{
	// Loop on all elements
	for(u32 i = 0; i<ptrList->ListSize; i++)
	{
		(*ptrFunction)(ptrList->Entry[i]);
	}
}


// Linked based implementations
#elif L_IMPLEMENTATION_METHOD == L_LINKED_BASED

// Function to initialize a list
void LIST_initializeList(List_type *ptrList)
{   
    ptrList->ptrHead = NULL;
	ptrList->ListSize = 0;
}

// Function to insert an element
void LIST_insertElement(ListEntry_type Element, u32 Position,List_type *ptrList)
{
	// Temp pointers to catch the nodes without memory leakage
	ListNode_type *Temp1,*Temp2;
	// Counter
	u32 i;
	// Allocate a memory for the new node to be inserted
	Temp1 = (ListNode_type *)malloc(sizeof(ListNode_type));
	// Assigen the element to the new node
	Temp1->Entry = Element;
	// Make the next pointer of the new node to point to nothing
	Temp1->ptrNext = NULL;
	// Check boundries
	if(Position == 0)
	{
		Temp1->ptrNext = ptrList->ptrHead;
		ptrList->ptrHead = Temp1;
	}
	else
	{
		// Determine the position to insert the new node at
		for(Temp2=ptrList->ptrHead,i=0;i<Position-1;i++)
		{
			Temp2 = Temp2->ptrNext;
		}
		Temp1->ptrNext = Temp2->ptrNext;
		Temp2->ptrNext = Temp1;
	}
	// Increment size of the list by 1
	ptrList->ListSize++;
}

// Function to get an element from the list
ListEntry_type LIST_deleteElement(u32 Position, List_type *ptrList)
{   
	// Temp pointers to catch the nodes without memory leakage
    ListNode_type *Temp1,*Temp2;
	ListEntry_type Temp;
	// Counter
	u32 i;
	// Check boundries
	if(Position == 0)
	{
		Temp = ptrList->ptrHead->Entry;
		Temp1 = ptrList->ptrHead->ptrNext;
		free(ptrList->ptrHead);
		ptrList->ptrHead = Temp1;
	}
	else
	{
		// Determine the position to delete the node at
		for(Temp1=ptrList->ptrHead,i=0;i<Position-1;i++)
		{
			Temp1 = Temp1->ptrNext;
		}
	    Temp = Temp1->ptrNext->Entry ;
		Temp2 = Temp1->ptrNext;
		Temp1->ptrNext = Temp2->ptrNext;
		free(Temp2);
	}
	// Decrement list size
	ptrList->ListSize--;
	// Return deleted node
	return Temp;
}


// Function to check if the list is full
u8 LIST_isFull(List_type *ptrList)
{
	return 0;
}

// Function to check if the list is empty
u8 LIST_isEmpty(List_type *ptrList)
{
	return !ptrList->ListSize;
}

// Function to get the size of list
u32 LIST_getCurrentSize(List_type *ptrList)
{
	return ptrList->ListSize;
}

// Function to destroy list
void LIST_destroyList(List_type *ptrList)
{
	// Auxilary pointer
	ListNode_type *Temp;
	while(ptrList->ptrHead)
	{
		Temp = ptrList->ptrHead->ptrNext;
		free(ptrList->ptrHead);
		ptrList->ptrHead = Temp;
	}
	ptrList->ListSize = 0;
}


// Function to retrieve an element
ListEntry_type LIST_retrieveElement(u32 Position,List_type *ptrList)
{
	// Auxilary pointer 
    ListNode_type *Temp;
	// Counter
	u32 i;
	// Loop on the list nodes
	for(Temp=ptrList->ptrHead,i=0;i<Position;i++)
	{	
		Temp = Temp->ptrNext;
	}
	return Temp->Entry;
}

// Function to replace an element
void LIST_replaceElement( ListEntry_type Element,u32 Position,List_type *ptrList)
{
	// Auxilary pointer
	ListNode_type *Temp;
	// Counter
	u32 i;
	// Loop on the list nodes
	for(Temp=ptrList->ptrHead,i=0;i<Position;i++)
	{	
		Temp = Temp->ptrNext;
	}
	Temp->Entry = Element;
}

// Function to traverse list
void LIST_traverseList(List_type *ptrList,void (*ptrFunction)(ListEntry_type))
{
	// Auxilary pointer
	ListNode_type *Temp = ptrList->ptrHead;
	// loop on all list nodes
	while(Temp)
	{
		(*ptrFunction)(Temp->Entry);
		Temp = Temp->ptrNext;
	}
}
#endif
