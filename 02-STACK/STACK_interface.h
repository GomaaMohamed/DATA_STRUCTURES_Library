/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _STACK_INTERFACE_H_
#define _STACK_INTERFACE_H_

/* Stacktype Definition */
typedef struct stack{
	StackNode *top;
	u32 Stack_Size;
}Stack;

/* it Initialize Stack */
void STACK_InitializeStack(Stack *ps);

/* 
*it Push an Element in The Stack
*Pre Condition: Stack is Initialized and not Full
*if Element Pushed Return 1 else return 0
*/
u8 STACK_Push(Stack_Entery e,Stack *ps);

/* 
*it Pop an Element from The Stack
*Pre Condition: Stack is Initialized and not Empty
*Return Value: Poped Element
*/
Stack_Entry STACK_Pop(Stack *ps);

/* 
*it Check if The Stack is FUll or Not
*Return Value: 1 if The Stack is Full else return 0
*/
u8 STACK_IsFull(Stack *ps);

/* 
*it Check if The Stack is FUll or Not 
*Return Value: 1 if The Stack is Empty else return 0
*/
u8 STACK_IsEmpty(Stack *ps);

/* 
*it take The Last Element in the Stack Without Pop it 
*Return Value: Top Element
*Pre Condition: Stack is Initialized and not Empty
*/
Stack_Entry STACK_Top(Stack *ps);

/* 
*it Indicate The Stack Size
*Return Value: Current Size Of Stack
*Pre Condition: Stack is Initialized 
*/
u32 STACK_CurrentSize(Stack *ps);

/* 
*it Clear The Stack
*Pre Condition: Stack is Initialized 
*/
void STACK_ClearStack(Stack *ps)

/* 
*it take all Elements in the Stack Without Pop them 
*Pre Condition: Stack is Initialized 
*/
void STACK_TraverseStack(Stack *ps,void (*pf)(Stack_Entry));

#endif