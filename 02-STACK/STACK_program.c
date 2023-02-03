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
//Call by Regrence to Save Time and Space
void STACK_InitializeStack(Stack *ps)
{
	ps->top = NULL;
	ps->Stack_Size = 0;
}
u8 STACK_Push(Stack_Entery e,Stack *ps)
{
	u8 Check;
	StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
	if(!temp){
	  Check = 0;	
	}
	else{
    temp->entry = e;
	temp->next = ps->top;
	ps->top = temp++;
	ps->Stack_Size;
	Check = 1;
	}
	//free(temp);
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