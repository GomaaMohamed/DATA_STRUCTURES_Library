/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _TREE_INTERFACE_H_
#define _TREE_INTERFACE_H_
//Stack and Queue is a Special Cases of List
/* TREE type Definition */
typedef struct tree{
	struct treenode *root;
	u32 Tree_Size;
	u32 Tree_Depth;
}Tree;

/* it Initialize Tree  */
void TREE_InitializeTree(Tree *pt);

/* 
*it Insert an Element in The List
*Pre Condition: List is Initialized and not Full
* 0 <= P <= List_Size
*/
void TREE_Insert(u32 P, List_Entery e,Tree *pt);

/* 
*it take an Element from The List
*Pre Condition: List is Initialized and not Empty
*/
void TREE_DeleteElement(u32 P, List_Entery e,Tree *pt);

/* 
*it Check if The List is FUll or Not
*Return Value: 1 if The List is Full else return 0
*/
u8 TREE_IsFull(Tree *pt);

/* 
*it Check if The List is FUll or Not 
*Return Value: 1 if The List sis Empty else return 0
*/
u8 TREE_IsEmpty(Tree *pt);

/* 
*it Indicate The List Size
*Return Value: Current Size Of List
*Pre Condition: List is Initialized 
*/
u32 TREE_CurrentSize(Tree *pt);

u32 Tree_CurrentDepth(Tree *pt);

/* 
*it Clear The List
*Pre Condition: List is Initialized 
*/
void TREE_DestroyList(Tree *pt);

/* 
*it take all Elements in the List Without Destroy it them 
*Pre Condition: List is Initialized 
*/
void TREE_RetrieveElement(u32 P, List_Entery e,Tree *pt);

/* 
*it Replace An Element In List
*Pre Condition: List is Initialized 
*/
void TREE_ReplaceElement(u32 P, List_Entery e,Tree *pt);

/* 
*it take all Elements in the List Without Destroy it them 
*Pre Condition: List is Initialized 
*/
void TREE_TraverseList(Tree *pt,void (*pf)(Tree_Entry));

#endif