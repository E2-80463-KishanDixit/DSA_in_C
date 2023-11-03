#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

typedef struct queue{
	int front;
	int rear;
	int arr[SIZE];
}queue;

void queue_init(queue*);
void insert_queue(queue * ,int);
void delete_queue(queue *);
int get_front(queue*);

int main(void){
	int choice,data;
	queue Q;
	queue_init(&Q);

	do{
		printf("Enter Your choice\n");
		printf("0.Exit\n1.insert value in Queue(Enqueue)\n2.delete value from queue(Dequeue)\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 0:
				exit(0);
				break;
			case 1:
				if(Q.rear == SIZE-1){
					printf("Queue is full\n");
				}else{
					printf("Enter data :\n");
					scanf("%d",&data);
					insert_queue(&Q,data);
					printf("%d is added in the queue",data);
				}
				break;
			case 2:
				if((Q.front == -1)|| (Q.front > Q.rear)){
					printf("Queue is empty\n");
				}else{
					int ele = get_front(&Q);
					delete_queue(&Q);
					printf("%d is removed from queue",ele);
					}
				break;
			default:
				printf("Enter valid choice\n");
		}
	}while(choice != 0);
	
return 0;
}

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




