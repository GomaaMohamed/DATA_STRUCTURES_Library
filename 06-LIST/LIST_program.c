/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2020                */
/* Version :V01                        */
/***************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "LIST_interface.h"
#include  "LIST_private.h"
#include  "LIST_config.h"
//Call by Regrence to Save Time and Space & Use % replacing if & Ckeck Boundry Condtions
void STACK_InitializeList(List *pl)//
{   
    pl->head = NULL;
	pl->List_Size = 0;
}
void List_Insert(u32 P, List_Entery e,List *pl)
{
	ListNode *temp1,temp2;
	u32 i;
	temp1 = (ListNode *)malloc(sizeof(ListNode));
	temp1->entry = e;
	temp1->next = NULL;
	if(P == 0){
		temp1->next = pl->head;
		pl->head = temp1;
	}
	else{
	for(temp2=pl->head,i=0;i<P-1;i++){
		temp2 = temp2->next;
	}
	    temp1->next = temp2->next;
		temp2->next = temp1;
	}
	List_Size++;
}
void LIST_DeleteElement(u32 P, List_Entery *pe,List *pl)
{    
    ListNode *temp1,temp2;
	u32 i;
	if(P == 0){
		*pe = pl->head->entry;
		temp1 = pl->head->next;
		free(pl->head);
		pl->head = temp1;
	}
	else{
	for(temp1=pl->head,i=0;i<P-1;i++){
		temp1 = temp1->next;
	}
	  *pe = temp1->next->entry ;
		temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}
	
	List_Size--;
}
u8 List_IsFull(List *pl)//
{
	return 0;
}
u8 LIST_IsEmpty(List *pl)//
{
	return !pl->List_Size;
}
u32 LIST_CurrentSize(List *pl)//
{
	return pl->List_Size;
}
void LIST_DestroyList(List *pl)//
{
	 ListNode *temp;
	 while(pl->head){
		 temp = pl->head->next;
		 free(pl->head);
		 pl->head = temp;
	 }
	 pl->List_Size = 0;
}
void LIST_RetrieveElement(u32 P, List_Entery *pe,List *pl)
{ 
    ListNode *temp;
	u32 i;
	for(temp=pl->head,i=0;i<P;i++){	
	  temp = temp->next;
	}
	*pe = temp->entry;
}
void LIST_ReplaceElement(u32 P, List_Entery e,List *pl)
{
	ListNode *temp;
	u32 i;
	for(temp=pl->head,i=0;i<P;i++){	
	  temp = temp->next;
	}
	temp->entry = e;
}
void LIST_TraverseList(List *pl,void (*pf)(List_Entry))//
{
	ListNode *temp = pl->head;
	while(temp)
	{
		(*fp)(temp->entry);
		temp = temp->next;
	}
}