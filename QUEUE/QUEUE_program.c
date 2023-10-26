/*****************************************************************************
* @file:    QUEUE_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   Queue module: Array based and Linked based methods are supported
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */ 

#include <stdlib.h>
#include  "QUEUE_private.h"
#include  "QUEUE_interface.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Array based implementations
#if Q_IMPLEMENTATION_METHOD == Q_ARRAY_BASED

// Function to initialize queue
void QUEUE_initializeQueue(Queue_type *ptrQueue)
{
	ptrQueue->Front = 0;
	ptrQueue->Rear = -1;
	ptrQueue->QueueSize = 0;	
}

// Function to append element in the queue
void QUEUE_appendElement(QueueEntry_type Element,Queue_type *ptrQueue)
{
	// Append an element at rear
	ptrQueue->Rear = (ptrQueue->Rear + 1) % MAX_QUEUE  ;
	ptrQueue->Entry[ptrQueue->Rear] = Element;
	ptrQueue->QueueSize++;
}

// Function to take an element from the queue
QueueEntry_type QUEUE_serveElement(Queue_type *ptrQueue)
{
	// Get an element at front
	QueueEntry_type Temp = ptrQueue->Entry[ptrQueue->Front];
	ptrQueue->Front = (ptrQueue->Front + 1) % MAX_QUEUE  ;
	ptrQueue->QueueSize--;
	return Temp;
}

// Function to check if the queue is empty or not
u8 QUEUE_isEmpty(Queue_type *ptrQueue)
{
	return !ptrQueue->QueueSize;
}

// Function to check if the queue is full or not
u8 QUEUE_isFull(Queue_type *ptrQueue)
{
	return (ptrQueue->QueueSize == MAX_QUEUE);
}

// Function to clear queue
void QUEUE_clearQueue(Queue_type *ptrQueue)
{
	ptrQueue->Front = 0;
	ptrQueue->Rear = -1;
	ptrQueue->QueueSize = 0;
}

// Function to get current queue size
u32 QUEUE_getCurrentSize(Queue_type *ptrQueue)
{
	return ptrQueue->QueueSize;
}

// Function to traverse queue
void QUEUE_traverseQueue(Queue_type *ptrQueue,void (*ptrFunction)(QueueEntry_type))
{   
	// Temp variable
    u32 Temp = ptrQueue->Front;
	u32 i;
	// Loop on all nodes of the queue
	for(Temp = ptrQueue->Front,i = 0; i<ptrQueue->QueueSize; i++)
	{
		(*ptrFunction)(ptrQueue->Entry[i]);
		Temp = (Temp + 1) % MAX_QUEUE;
	}
}


// Linked based implementations
#elif Q_IMPLEMENTATION_METHOD == Q_LINKED_BASED

// Function to initialize queue
void QUEUE_initializeQueue(Queue_type *ptrQueue)
{
	ptrQueue->ptrFront = NULL;
	ptrQueue->ptrRear  = NULL;
	ptrQueue->QueueSize = 0;
}

// Function to append element in the queue
void QUEUE_appendElement(QueueEntry_type Element,Queue_type *ptrQueue)
{   
	// Flag
	u8 Check;
	// Allocate memory for the new node
	QueueNode_type *Temp = (QueueNode_type *)malloc(sizeof(QueueNode_type));
	// Check boundries
	if(!Temp)
	{
		Check = 0;
	}
	else
	{
		Temp->ptrNext = NULL;
		Temp->Entry = Element;
		if(!ptrQueue->ptrRear)
		{
			ptrQueue->ptrFront = Temp;
		}
		else
		{
			ptrQueue->ptrRear->ptrNext = Temp;
		}
		ptrQueue->ptrRear = Temp;
		ptrQueue->QueueSize++;
		Check = 1;
	}
}

// Function to take an element from the queue
QueueEntry_type QUEUE_serveElement(Queue_type *ptrQueue)
{
	// Temp variable
	QueueEntry_type TempValue = ptrQueue->ptrFront->Entry;
	// Temp node
	QueueNode_type *Temp = ptrQueue->ptrFront;
	if(ptrQueue->QueueSize == 1)
	{
		ptrQueue->ptrFront = NULL;
		ptrQueue->ptrRear  = NULL;
	}
	else
	{
		ptrQueue->ptrFront = Temp->ptrNext; 
	}
	free(Temp);
	ptrQueue->QueueSize--;
	return TempValue;
}

// Function to check if the queue is empty or not
u8 QUEUE_isEmpty(Queue_type *ptrQueue)
{
	return !ptrQueue->QueueSize;
}

// Function to check if the queue is full or not
u8 QUEUE_isFull(Queue_type *ptrQueue)
{
	return 0;
}

// Function to clear queue
void QUEUE_clearQueue(Queue_type *ptrQueue)
{
	// Loop on all nodes and clear them
	while(ptrQueue->ptrFront)
	{
		ptrQueue->ptrRear = ptrQueue->ptrFront->ptrNext;
		free(ptrQueue->ptrFront);
		ptrQueue->ptrFront = ptrQueue->ptrRear;
	}
	ptrQueue->QueueSize = 0;
}

// Function to get current queue size
u32 QUEUE_getCurrentSize(Queue_type *ptrQueue)
{
	return ptrQueue->QueueSize;
}
#endif
