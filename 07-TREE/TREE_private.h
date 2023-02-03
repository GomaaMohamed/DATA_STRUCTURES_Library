/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _TREE_PRIVATE_H_
#define _TREE_PRIVATE_H_

typedef struct treenode{
	struct treenode *left,*right;
	Tree_Entry entry;
}TreeNode;


#endif