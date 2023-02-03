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
void STACK_InitializeList(List *pl)
{
	pl->List_Size = 0;
}
void List_Insert(u32 P, List_Entery e,List *pl)
{
	u32 i;
	for(i=pl->List_Size-1;i >= P;i--){
		pl->entry[i+1] = pl->entry[i];
	}
	pl->entry[P] = e;
	List_Size++;
}
void LIST_DeleteElement(u32 P, List_Entery *pe,List *pl)
{    
    *pe = pl->entry[P];
	u32 i;
	for(i=P+1;i <= pl->List_Size-1 ;i++){
		pl->entry[i-1] = pl->entry[i];
	}
	List_Size--;
}
u8 List_IsFull(List *pl)
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
void LIST_RetrieveElement(u32 P, List_Entery *pe,List *pl)
{
	*pe = pl->entry[P];
}
void LIST_ReplaceElement(u32 P, List_Entery e,List *pl)
{
	pl->entry[P] = e ;
}
void LIST_TraverseList(List *pl,void (*pf)(List_Entry))
{
	for(u32 i = 0; i<pl->List_Size; i++)
	{
		(*fp)(pl->entry[i]);
	}
}