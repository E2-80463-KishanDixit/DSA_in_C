#include "header.h"

void queue_init(queue *pq){
	pq->front = -1;
	pq->rear = -1;
}

void insert_queue(queue *pq ,int data){
	pq->rear++;
	pq->arr[pq->rear] = data;
	
	if( pq->front == -1){
		pq->front++;
	}
}

void delete_queue(queue *pq){
	pq->arr[pq->front] =0;
	pq->front++;
}

int get_front(queue *pq){
	return pq->arr[pq->front];
}



