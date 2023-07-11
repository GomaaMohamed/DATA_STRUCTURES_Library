/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _QUEUE_INTERFACE_H_
#define _QUEUE_INTERFACE_H_

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "QUEUE_config.h"

/* ==================================================================== */
/* ======================= public data types ========================== */
/* ==================================================================== */

/* Queue type Definition */
#if Q_IMPLEMENTATION_METHOD == Q_ARRAY_BASED
typedef struct queue{
	Queue_Entry entry[MAX_QUEUE];
	u32 front;
	u32 rear;
	u32 Queue_Size;
}Queue;
#elif Q_IMPLEMENTATION_METHOD == Q_LINKED_BASED
typedef struct queuenode{
	Queue_Entry entry;
	struct queuenode *next;
}QueueNode;
typedef struct queue{
	QueueNode *front;
	QueueNode *rear;
	u32 Queue_Size;
}Queue;
#endif

/* ==================================================================== */
/* ==================== public functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief   initialize the queue
 * @param   pq pointer to the queue that will be initialized
 * @return  None
 * @example
 *          ex:   Queue q;
 *                QUEUE_InitializeQueue(&q);
 */ 
void QUEUE_InitializeQueue(Queue *pq);

/**
 * @brief   append an element in the queue
 * @param   e the element that will be appended in the queue
 * @param   pq pointer to the que that the element will be appemded inside 
 * @return  none
 * @pre     queue is initialized and not full
 * @example
 *          ex:   Queue q;
 *                QUEUE_Append(5,&q);
 */ 
u8 QUEUE_Append(Queue_Entry e,Queue *pq);

/**
 * @brief   take an element from the queue
 * @param   e the element that will be taken from the queue
 * @param   pq pointer to the queue that the element will be taken from 
 * @return  the taken element
 * @pre     queue is initialized and not empty
 * @example
 *          ex:   Queue q;
 *                QUEUE_Serve(5,&q);
 */ 
Queue_Entry QUEUE_Serve(Queue *pq);

/**
 * @brief   Check if the queue is empty or not
 * @return  1 if the queue is empty else it returns 0
 * @pre     queue is initialized 
 * @example
 *          ex:   u8 check;
 *                QUEUE_IsEmpty(5,&q);
 */ 
u8 QUEUE_IsEmpty(Queue *pq);

/**
 * @brief   check if the queue is full or not
 * @return  1 if the queue is full else it returns 0
 * @pre     queue is initialized 
 * @example
 *          ex:   u8 check;
 *                check = QUEUE_IsFull(&q);
 */ 
u8 QUEUE_IsFull(Queue *pq);

/**
 * @brief   clear the queue
 * @param   pq pointer to the queue that will be cleared 
 * @return  none
 * @pre     queue is initialized 
 * @example
 *          ex:   QUEUE_ClearQueue(&q);
 */
void QUEUE_ClearQueue(Queue *pq);

/**
 * @brief   get the current size of the queue
 * @param   pq pointer to the queue that its size will be taken 
 * @return  queue size
 * @pre     queue is initialized 
 * @example
 *          ex:   u32 size;
 *                size = QUEUE_CurrentSize(&q);
 */ 
u32 QUEUE_CurrentSize(Queue *pq);

#endif
