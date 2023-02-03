/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2020                */
/* Version :V01                        */
/***************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "STACK_interface.h"
#include  "STACK_private.h"
#include  "STACK_config.h"
//Call by Regrence to Save Time and Space & Use % replacing if & Ckeck Boundry Condtions
void STACK_InitializeStack(Stack *ps)
{
	ps->top = 0;
}
void STACK_Push(Stack_Entery e,Stack *ps)
{
	ps->entry[ps->top] = e;
	ps->top++;
	//ps->entry[ps->top++] = e;
}
Stack_Entry STACK_Pop(Stack *ps)
{    ps->top--;
    
	return ps->entry[ps->top];
}
u8 STACK_IsFull(Stack *ps)
{
	u8 Check = 0;
	if(ps->top != MAX_STACK)
	{
		Check = 0;
	}
	else
	{
		Check = 1;
	}
	return Check;
}
u8 STACK_IsEmpty(Stack *ps)
{
	u8 Check = 0;
	if(ps->top == 0)
	{
		Check = 1;
	}
	else
	{
		Check = 0;
	}
	return Check;
}
Stack_Entry STACK_Top(Stack *ps)
{
	return ps->entry[ps->top-1];
}
u32 STACK_CurrentSize(Stack *ps)
{
	return ps->top;
}
void STACK_ClearStack(Stack *ps)
{
	 ps->top = 0;
}
void STACK_TraverseStack(Stack *ps,void (*pf)(Stack_Entry))
{
	for(u32 i = ps->top; i>0; i--)
	{
		(*fp)(ps->entry[i-1]);
	}
}