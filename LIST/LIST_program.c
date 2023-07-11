/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2020                */
/* Version :V01                        */
/***************************************/

#include <stdlib.h>
#include  "LIST_private.h"
#include  "LIST_interface.h"

#if L_IMPLEMENTATION_METHOD == L_ARRAY_BASED
void LIST_InitializeList(List *pl)
{
	pl->List_Size = 0;
}
void LIST_Insert(u32 P, List_Entry e,List *pl)
{
	if (pl->List_Size == 0)
	{
		pl->entry[P] = e;
	}
	else{
	u32 i;
	for(i=pl->List_Size-1;i >= P;i--){
		pl->entry[i+1] = pl->entry[i];
	}
	pl->entry[P] = e;
	}
	pl->List_Size++;
}
List_Entry LIST_DeleteElement(u32 P,List *pl)
{    
    List_Entry temp = pl->entry[P];
	u32 i;
	for(i=P+1;i <= pl->List_Size-1 ;i++){
		pl->entry[i-1] = pl->entry[i];
	}
	pl->List_Size--;
	return temp;
}
u8 LIST_IsFull(List *pl)
{
	return (pl->List_Size == MAX_LIST);
}
u8 LIST_IsEmpty(List *pl)
{
	return !pl->List_Size;
}
u32 LIST_CurrentSize(List *pl)
{
	return pl->List_Size;
}
void LIST_DestroyList(List *pl)
{
	 pl->List_Size = 0;
}
List_Entry LIST_RetrieveElement(u32 P,List *pl)
{
	return pl->entry[P];
}
void LIST_ReplaceElement(u32 P, List_Entry e,List *pl)
{
	pl->entry[P] = e ;
}
void LIST_TraverseList(List *pl,void (*pf)(List_Entry))
{
	for(u32 i = 0; i<pl->List_Size; i++)
	{
		(*pf)(pl->entry[i]);
	}
}
#elif L_IMPLEMENTATION_METHOD == L_LINKED_BASED
void LIST_InitializeList(List *pl)
{   
    pl->head = NULL;
	pl->List_Size = 0;
}
void LIST_Insert(u32 P, List_Entry e,List *pl)
{
	ListNode *temp1,*temp2;
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
	pl->List_Size++;
}
List_Entry LIST_DeleteElement(u32 P,List *pl)
{    
    ListNode *temp1,*temp2;
	List_Entry temp;
	u32 i;
	if(P == 0){
		temp = pl->head->entry;
		temp1 = pl->head->next;
		free(pl->head);
		pl->head = temp1;
	}
	else{
	for(temp1=pl->head,i=0;i<P-1;i++){
		temp1 = temp1->next;
	}
	    temp = temp1->next->entry ;
		temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}
	
	pl->List_Size--;
	return temp;
}
u8 LIST_IsFull(List *pl)//
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
List_Entry LIST_RetrieveElement(u32 P,List *pl)
{ 
    ListNode *temp;
	u32 i;
	for(temp=pl->head,i=0;i<P;i++){	
	  temp = temp->next;
	}
	return temp->entry;
}
void LIST_ReplaceElement(u32 P, List_Entry e,List *pl)
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
		(*pf)(temp->entry);
		temp = temp->next;
	}
}
#endif
