/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2020                */
/* Version :V01                        */
/***************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "QUEUE_interface.h"
#include  "QUEUE_private.h"
#include  "QUEUE_config.h"
//Call by Regrence to Save Time and Space
void QUEUE_InitializeQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->Queue_Size = 0;
	
}
void QUEUE_Append(Queue_Entry e,Queue *pq)
{
	pq->rear = (pq->rear + 1) % MAX_QUEUE  ;
	pq->entry[pq->rear] = e;
	pq->Queue_Size++;
}
void QUEUE_Serve(Queue_Entry *pe,Queue *pq)
{
	*pe = pq->entry[pq->front];
	pq->front = (pq->front + 1) % MAX_QUEUE  ;
	pq->Queue_Size--;
}
u8 QUEUE_IsEmpty(Queue *pq)
{
	return !pq->Queue_Size;
}
u8 QUEUE_IsFull(Queue *pq)
{
	return (pq->Queue_Size == MAX_QUEUE);
}
void QUEUE_ClearQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->Queue_Size = 0;
}
u32 QUEUE_CurrentSize(Queue *pq)
{
	return pq->Queue_Size;
}
void STACK_TraverseQueue(Queue *pq,void (*pf)(Queue_Entry))
{   
    u32 temp = pq->front;
	u32 i;
	for(temp = pq->front,i = 0; i<pq->Queue_Size; i++)
	{
		(*fp)(pq->entry[i]);
		temp = (temp + 1) % MAX_QUEUE;
	}
}
