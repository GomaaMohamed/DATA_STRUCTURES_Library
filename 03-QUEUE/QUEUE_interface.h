/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _QUEUE_INTERFACE_H_
#define _QUEUE_INTERFACE_H_

/* Queue Definition */
typedef struct queue{
	Queue_Entry entry[MAX_QUEUE];
	u32 front;
	u32 rear;
	u32 Queue_Size;
}Queue;

/* it Initialize The Queue */
void QUEUE_InitializeStack(Stack *ps);

/* it append Element to Queue */
void QUEUE_Append(Queue_Entry e,Queue *pq);

/* it Serve Element from Queue */
void QUEUE_Serve(Queue_Entry *pe,Queue *pq);

/* Check if the queue is empty or not */
u8 QUEUE_IsEmpty(Queue *pq);

/* Check if the queue is Full or not */
u8 QUEUE_IsFull(Queue *pq);

/* it Clear The queue */
void QUEUE_ClearQueue(Queue *pq);

/* it ndicate Queue Size */
u32 QUEUE_CurrentSize(Queue *pq);

#endif