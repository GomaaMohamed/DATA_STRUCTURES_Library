/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _QUEUE_PRIVATE_H_
#define _QUEUE_PRIVATE_H_

typedef struct queuenode{
	QueueEntry entry;
	struct queuenode *next;
}QueueNode;




#endif