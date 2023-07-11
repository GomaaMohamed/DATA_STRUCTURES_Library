/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2020                */
/* Version :V01                        */
/***************************************/

#include <stdlib.h>
#include  "STACK_private.h"
#include  "STACK_interface.h"



#if IMPLEMENTATION_METHOD == LINKED_BASED

#endif


#if IMPLEMENTATION_METHOD == ARRAY_BASED
//Call by Regrence to Save Time and Space & Use % replacing if & Ckeck Boundry Condtions
void STACK_InitializeStack(Stack *ps)
{
	ps->top = 0;
}
u8 STACK_Push(Stack_Entry e,Stack *ps)
{
	ps->entry[ps->top] = e;
	ps->top++;
	return 1;
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
		(*pf)(ps->entry[i-1]);
	}
}

#elif IMPLEMENTATION_METHOD == LINKED_BASED
void STACK_InitializeStack(Stack *ps)
{
	ps->top = NULL;
	ps->Stack_Size = 0;
}
u8 STACK_Push(Stack_Entry e,Stack *ps)
{
	u8 Check;
	StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
	if(!temp){
	  Check = 0;	
	}
	else{
    temp->entry = e;
	temp->next = ps->top;
	ps->top = temp;
	ps->Stack_Size++;
	Check = 1;
	}
	return Check;
}
Stack_Entry STACK_Pop(Stack *ps)
{   
    Stack_Entry data = ps->top->entry;
    StackNode *temp = ps->top;
	ps->top = temp->next;
	free(temp);
	ps->Stack_Size--;
	return data;
}

u8 STACK_IsFull(Stack *ps)
{
	return 0;
}
u8 STACK_IsEmpty(Stack *ps)
{
	return !(ps->top);
}
Stack_Entry STACK_Top(Stack *ps)
{
	return ps->top->entry;
}
u32 STACK_CurrentSize(Stack *ps)
{
	return ps->Stack_Size;
}
void STACK_ClearStack(Stack *ps)
{
	 StackNode *temp1 = ps->top;
	 StackNode *temp2 = ps->top;
	 //while temp1 != NULL
	 while(temp1){
	 temp1 = temp1->next;
	 free(temp2);
	 temp2=temp1;
	           }
	 ps->top = NULL;
	 ps->Stack_Size = 0;
	 
}
void STACK_TraverseStack(Stack *ps,void (*pf)(Stack_Entry))
{   
	 StackNode *temp = ps->top;
	 //while temp1 != NULL
	 while(temp ){
	 (*pf)(temp->entry);
	 temp=temp->next;
	           }
}
#endif