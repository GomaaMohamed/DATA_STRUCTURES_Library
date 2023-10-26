/*****************************************************************************
* @file:    STACK_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   Stack module: Array based and Linked based methods are supported
******************************************************************************/
#ifndef _STACK_INTERFACE_H_
#define _STACK_INTERFACE_H_

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "STACK_config.h"

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* Stack type Definition */
#if IMPLEMENTATION_METHOD == ARRAY_BASED
typedef struct stack
{
	u32 Top;
	StackEntry_type Entry[MAX_STACK];
}Stack_type;
#elif IMPLEMENTATION_METHOD == LINKED_BASED
typedef struct stacknode
{
	StackEntry_type Entry;
	struct stacknode *ptrNext;
}StackNode_type;
typedef struct stack
{
	StackNode_type *Top;
	u32 StackSize;
}Stack_type;
#endif

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize stack
 * @parameter1----------------> (ptrStack) pointer to the stack to be initialized
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant 
 */
void STACK_initializeStack(Stack_type *ptrStack);

/**
 * @brief---------------------> Push an element in the stack
 * @parameter1----------------> (Element) the element that will be pushed in the stack
 * @parameter2----------------> (ptrStack) pointer to the stack
 * @return--------------------> None
 * @preconditions-------------> Stack is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
void STACK_pushElement(StackEntry_type Element, Stack_type *ptrStack);

/**
 * @brief---------------------> Pop an element from the stack
 * @parameter1----------------> (ptrStack) pointer to the stack
 * @return--------------------> Element
 * @preconditions-------------> Stack is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
StackEntry_type STACK_PopElement(Stack_type *ptrStack);

/**
 * @brief---------------------> Check if the stack is full or not
 * @parameter1----------------> (ptrStack) pointer to the stack be checked
 * @return--------------------> 1 if it is full else it return 0
 * @preconditions-------------> Stack is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u8 STACK_isFull(Stack_type *ptrStack);

/**
 * @brief---------------------> Check if the stack is empty or not
 * @parameter1----------------> (ptrStack) pointer to the stack be checked
 * @return--------------------> 1 if it is full else it return 0
 * @preconditions-------------> Stack is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u8 STACK_isEmpty(Stack_type *ptrStack);

/**
 * @brief---------------------> Get top element of the stack 
 * @parameter1----------------> (ptrStack) pointer to the stack 
 * @return--------------------> Top element
 * @preconditions-------------> Stack is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
StackEntry_type STACK_getTop(Stack_type *ptrStack);

/**
 * @brief---------------------> Get current size of the stack 
 * @parameter1----------------> (ptrStack) pointer to the stack 
 * @return--------------------> Current size
 * @preconditions-------------> Stack is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u32 STACK_getCurrentSize(Stack_type *ptrStack);

/**
 * @brief---------------------> Clear stack 
 * @parameter1----------------> (ptrStack) pointer to the stack 
 * @return--------------------> None
 * @preconditions-------------> Stack is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
void STACK_clearStack(Stack_type *ptrStack);
 
/**
 * @brief---------------------> Traverse all elements of the stack
 * @parameter1----------------> (ptrStack) pointer to the stack to be traversed
 * @parameter2----------------> (ptrFunction) pointer to the function that will be performed on the stack elements
 * @return--------------------> None
 * @preconditions-------------> Stack is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
void STACK_traverseStack(Stack_type *ptrStack,void (*ptrFunction)(StackEntry_type));

#endif
