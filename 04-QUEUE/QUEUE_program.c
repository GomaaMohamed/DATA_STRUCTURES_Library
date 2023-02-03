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
		pq->rear = temp;
		pq->Queue_Size++;
	}
	Check = 1;
	}
	return Check;
}
void QUEUE_Serve(Queue_Entry *pe,Queue *pq)
{
	*pe = pq->front->entry;
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
	Queue_Size = 0;
}
u32 QUEUE_CurrentSize(Queue *pq)
{
	return pq->Queue_Size;
}
