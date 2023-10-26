/*****************************************************************************
* @file:    STACK_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   Stack module: Array based and Linked based methods are supported
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */ 

#include  <stdlib.h>
#include  "STACK_private.h"
#include  "STACK_interface.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Array based implementations
#if IMPLEMENTATION_METHOD == ARRAY_BASED

// Function to initialize stack
void STACK_initializeStack(Stack_type *ptrStack)
{
	ptrStack->Top = 0;
}

// Function to push an element in the stack
void STACK_pushElement(StackEntry_type Element, Stack_type *ptrStack)
{
	// Push element
	ptrStack->Entry[ptrStack->Top] = Element;
	// increment stack pointer
	ptrStack->Top++;
}

// Function to pop element from the stack
StackEntry_type STACK_PopElement(Stack_type *ptrStack)
{   
	// Decrement stack pointer
	ptrStack->Top--;
	// Return element
	return ptrStack->Entry[ptrStack->Top];
}

// Function to check if the stack is full or not
u8 STACK_isFull(Stack_type *ptrStack)
{
	// Flag
	u8 Check = 0;
	// Check boundries
	if(ptrStack->Top != MAX_STACK)
	{
		Check = 0;
	}
	else
	{
		Check = 1;
	}
	return Check;
}

// Function to check if the stack is empty or not
u8 STACK_isEmpty(Stack_type *ptrStack)
{
	// Flag
	u8 Check = 0;
	// Check boundries
	if(ptrStack->Top == 0)
	{
		Check = 1;
	}
	else
	{
		Check = 0;
	}
	return Check;
}

// Function to get the top element of the stack
StackEntry_type STACK_getTop(Stack_type *ptrStack)
{
	return ptrStack->Entry[ptrStack->Top-1];
}

// Function to get the current size of the stack
u32 STACK_getCurrentSize(Stack_type *ptrStack)
{
	return ptrStack->Top;
}

// Function to clear stack
void STACK_clearStack(Stack_type *ptrStack)
{
	ptrStack->Top = 0;
}

// Function to traverse stack 
void STACK_traverseStack(Stack_type *ptrStack,void (*ptrFunction)(StackEntry_type))
{
	// Loop on all stack elements
	for(u32 i = ptrStack->Top; i>0; i--)
	{
		(*ptrFunction)(ptrStack->Entry[i-1]);
	}
}


// Linked based implementations
#elif IMPLEMENTATION_METHOD == LINKED_BASED

// Function to initialize stack
void STACK_initializeStack(Stack_type *ptrStack)
{
	ptrStack->Top = NULL;
	ptrStack->StackSize = 0;
}

// Function to push an element in the stack
void STACK_pushElement(StackEntry_type Element, Stack_type *ptrStack)
{
	// Alocate memory for the new stack node
	StackNode_type *Temp = (StackNode_type *) malloc(sizeof(StackNode_type));
	// Check boundries
	// Push element
    Temp->Entry = Element;
	Temp->ptrNext = ptrStack->Top;
	ptrStack->Top = Temp;
	ptrStack->StackSize++;		
}

// Function to pop an element from the stack
StackEntry_type STACK_PopElement(Stack_type *ptrStack)
{   
	// Temp variable to hold the element
    StackEntry_type Data = ptrStack->Top->Entry;
	// Auxilary pointer
    StackNode_type *Temp = ptrStack->Top;
	ptrStack->Top = Temp->ptrNext;
	free(Temp);
	ptrStack->StackSize--;
	return Data;
}

// Function to check if the stack is full or not
u8 STACK_isFull(Stack_type *ptrStack)
{
	return 0;
}

// Function to check if the stack is empty or not
u8 STACK_isEmpty(Stack_type *ptrStack)
{
	return !(ptrStack->Top);
}

// Function to get the top element of the stack
StackEntry_type STACK_getTop(Stack_type *ptrStack)
{
	return ptrStack->Top->Entry;
}

// Function to get the current size of the stack
u32 STACK_getCurrentSize(Stack_type *ptrStack)
{
	return ptrStack->StackSize;
}

// Function to clear stack
void STACK_clearStack(Stack_type *ptrStack)
{
	// Auxilary pointers
	StackNode_type *Temp1 = ptrStack->Top;
	StackNode_type *Temp2 = ptrStack->Top;
	// while temp1 != NULL
	while(Temp1)
	{
		// delete all elements
		Temp1 = Temp1->ptrNext;
		free(Temp2);
		Temp2=Temp1;
	}
	ptrStack->Top = NULL;
	ptrStack->StackSize = 0;	
}

// Function to traverse stack 
void STACK_traverseStack(Stack_type *ptrStack,void (*ptrFunction)(StackEntry_type))
{   
	// Auxilary pointer
	StackNode_type *Temp = ptrStack->Top;
	// while temp1 != NULL
	while(Temp)
	{
		(*ptrFunction)(Temp->Entry);
		Temp=Temp->ptrNext;
	}
}
#endif