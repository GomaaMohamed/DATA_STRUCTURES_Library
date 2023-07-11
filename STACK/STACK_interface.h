/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _STACK_INTERFACE_H_
#define _STACK_INTERFACE_H_

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "STACK_config.h"


/* ==================================================================== */
/* ======================= public data types ========================== */
/* ==================================================================== */

/* Stack type Definition */
#if IMPLEMENTATION_METHOD == ARRAY_BASED
typedef struct stack{
	u32 top;
	Stack_Entry entry[MAX_STACK];
}Stack;
#elif IMPLEMENTATION_METHOD == LINKED_BASED
typedef struct stacknode{
	Stack_Entry entry;
	struct stacknode *next;
}StackNode;
typedef struct stack{
	StackNode *top;
	u32 Stack_Size;
}Stack;
#endif

/* ==================================================================== */
/* ==================== public functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief   initialize the stack
 * @param   ps pointer to the stack that will be initialized
 * @return  None
 * @example
 *          ex:   Stack s1;
 *                STACK_InitializeStack(&s1);
 */ 
void STACK_InitializeStack(Stack *ps);

/**
 * @brief   push an element in the stack
 * @param   e the element that will be pushed in the stack
 * @param   ps pointer to the stack that the element will be pushed inside 
 * @return  none
 * @pre     stack is initialized and not full
 * @example
 *          ex:   Stack s1;
 *                STACK_Push(5,&s1);
 */ 
u8 STACK_Push(Stack_Entry e,Stack *ps);

/**
 * @brief   Pop an element from the stack
 * @param   e the element that will be poped from the stack
 * @param   ps pointer to the stack that the element will be poped from 
 * @return  the poped element
 * @pre     stack is initialized and not empty
 * @example
 *          ex:   Stack s1;
 *                STACK_Push(5,&s1);
 */ 
Stack_Entry STACK_Pop(Stack *ps);

/**
 * @brief   check if the stack is full or not
 * @return  1 if the stack is full else it returns 0
 * @pre     stack is initialized 
 * @example
 *          ex:   u8 check;
 *                check = STACK_IsFull(&s1);
 */ 
u8 STACK_IsFull(Stack *ps);

/**
 * @brief   Check if the stack is empty or not
 * @return  1 if the stack is empty else it returns 0
 * @pre     stack is initialized 
 * @example
 *          ex:   u8 check;
 *                STACK_IsEmpty(5,&s1);
 */ 
u8 STACK_IsEmpty(Stack *ps);

/**
 * @brief   get the top element from the stack
 * @param   ps pointer to the stack that the element will be taken from 
 * @return  the taken element
 * @pre     stack is initialized and not empty
 * @example
 *          ex:   u8 element;
 *               element = STACK_Top(&s1);
 */ 
Stack_Entry STACK_Top(Stack *ps);

/**
 * @brief   get the current size of the stack
 * @param   ps pointer to the stack that its size will be taken 
 * @return  stack size
 * @pre     stack is initialized 
 * @example
 *          ex:   u32 size;
 *                size = STACK_CurrentSize(&s1);
 */ 
u32 STACK_CurrentSize(Stack *ps);

/**
 * @brief   clear the stack
 * @param   ps pointer to the stack that will be cleared 
 * @return  none
 * @pre     stack is initialized 
 * @example
 *          ex:   STACK_ClearStack(&s1);
 */
void STACK_ClearStack(Stack *ps);

/**
 * @brief   traverse all elements of the stack
 * @param   ps pointer to the stack that will be traversed
 * @param   pf pointer to the function that will be performed on the stack elements
 * @return  none
 * @pre     stack is initialized 
 * @example
 *          ex:   Stack s1;  
 *                STACK_TraverseStack(&s1,func);
 */ 
void STACK_TraverseStack(Stack *ps,void (*pf)(Stack_Entry));

#endif
