/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2020                 */
/* Version :V01                        */
/***************************************/

#include <stdlib.h>
#include  "QUEUE_private.h"
#include  "QUEUE_interface.h"




/* ==================================================================== */
/* ================= Public functions Implementation ================== */
/* ==================================================================== */
#if Q_IMPLEMENTATION_METHOD == Q_ARRAY_BASED
void QUEUE_InitializeQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->Queue_Size = 0;
	
}
u8 QUEUE_Append(Queue_Entry e,Queue *pq)
{
	pq->rear = (pq->rear + 1) % MAX_QUEUE  ;
	pq->entry[pq->rear] = e;
	pq->Queue_Size++;
	return 1
}
Queue_Entry QUEUE_Serve(Queue *pq)
{
	Queue_Entry temp = pq->entry[pq->front];
	pq->front = (pq->front + 1) % MAX_QUEUE  ;
	pq->Queue_Size--;
	return temp;
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
		(*pf)(pq->entry[i]);
		temp = (temp + 1) % MAX_QUEUE;
	}
}
#elif Q_IMPLEMENTATION_METHOD == Q_LINKED_BASED
void QUEUE_InitializeQueue(Queue *pq)
{
	pq->front = NULL;
	pq->rear  = NULL;
	pq->Queue_Size = 0;
}
u8 QUEUE_Append(Queue_Entry e,Queue *pq)
{   u8 Check;
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if(!temp){
		Check = 0;
	}
	else{
	temp->next = NULL;
	temp->entry = e;
	if(!pq->rear){
		pq->front = temp;
	}
	else{
		pq->rear->next = temp;
	}
	pq->rear = temp;
	pq->Queue_Size++;
	Check = 1;
	}
	return Check;
}
Queue_Entry QUEUE_Serve(Queue *pq)
{
	Queue_Entry tempval = pq->front->entry;
	QueueNode *temp = pq->front;
	if(pq->Queue_Size == 1){
	pq->front = NULL;
	pq->rear  = NULL;
	}
	else{
	pq->front = temp->next; //pq->front =pq->front->next
	}
	free(temp);
	pq->Queue_Size--;
	return tempval;
}
u8 QUEUE_IsEmpty(Queue *pq)
{
	return !pq->Queue_Size;
}
u8 QUEUE_IsFull(Queue *pq)
{
	return 0;
}
void QUEUE_ClearQueue(Queue *pq)
{
	while(pq->front){
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->Queue_Size = 0;
}
u32 QUEUE_CurrentSize(Queue *pq)
{
	return pq->Queue_Size;
}
#endif
