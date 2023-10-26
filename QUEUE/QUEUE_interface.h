/*****************************************************************************
* @file:    QUEUE_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   Queue module: Array based and Linked based methods are supported
******************************************************************************/
#ifndef _QUEUE_INTERFACE_H
#define _QUEUE_INTERFACE_H

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "QUEUE_config.h"

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* Queue type Definition */
#if Q_IMPLEMENTATION_METHOD == Q_ARRAY_BASED
typedef struct queue
{
	QueueEntry_type Entry[MAX_QUEUE];
	u32 Front;
	u32 Rear;
	u32 QueueSize;
}Queue_type;
#elif Q_IMPLEMENTATION_METHOD == Q_LINKED_BASED
typedef struct queuenode
{
	QueueEntry_type Entry;
	struct queuenode *ptrNext;
}QueueNode_type;
typedef struct queue
{
	QueueNode_type *ptrFront;
	QueueNode_type *ptrRear;
	u32 QueueSize;
}Queue_type;
#endif

/* ==================================================================== */
/* ==================== public functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize queue
 * @parameter1----------------> (ptrQueue) pointer to the queue to be initialized
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant 
 */
void QUEUE_initializeQueue(Queue_type *ptrQueue);

/**
 * @brief---------------------> Append an element in the queue
 * @parameter1----------------> (Element) the element that will be appended 
 * @parameter2----------------> (ptrQueue) pointer to the queue
 * @return--------------------> None
 * @preconditions-------------> Queue is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
void QUEUE_appendElement(QueueEntry_type Element,Queue_type *ptrQueue);

/**
 * @brief---------------------> Take an element from the queue
 * @parameter1----------------> (ptrQueue) pointer to the queue
 * @return--------------------> Element
 * @preconditions-------------> Queue is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
QueueEntry_type QUEUE_serveElement(Queue_type *ptrQueue);

/**
 * @brief---------------------> Check if the queue is empty or not
 * @parameter1----------------> (ptrQueue) pointer to the queue be checked
 * @return--------------------> 1 if it is empty else it return 0
 * @preconditions-------------> Queue is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u8 QUEUE_isEmpty(Queue_type *ptrQueue);

/**
 * @brief---------------------> Check if the queue is full or not
 * @parameter1----------------> (ptrQueue) pointer to the queue be checked
 * @return--------------------> 1 if it is full else it return 0
 * @preconditions-------------> Queue is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u8 QUEUE_isFull(Queue_type *ptrQueue);

/**
 * @brief---------------------> Clear queue
 * @parameter1----------------> (ptrQueue) pointer to the queue 
 * @return--------------------> None
 * @preconditions-------------> Queue is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
void QUEUE_clearQueue(Queue_type *ptrQueue);

/**
 * @brief---------------------> Get current size of the queue 
 * @parameter1----------------> (ptrQueue) pointer to the queue
 * @return--------------------> Current size
 * @preconditions-------------> Queue is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */ 
u32 QUEUE_getCurrentSize(Queue_type *ptrQueue);

/**
 * @brief---------------------> Traverse all elements of the queue
 * @parameter1----------------> (ptrQueue) pointer to the queue to be traversed
 * @parameter2----------------> (ptrFunction) pointer to the function that will be performed on the queue elements
 * @return--------------------> None
 * @preconditions-------------> Queue is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant 
 */
void QUEUE_traverseQueue(Queue_type *ptrQueue, void (*ptrFunction)(QueueEntry_type));

#endif
