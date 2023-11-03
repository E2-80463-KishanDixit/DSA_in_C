#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct queue{
	int front;
	int rear;
	int arr[SIZE];
}queue;

void queue_init(queue*);
void enqueue(queue * ,int);
void dequeue(queue *);
int get_front(queue*);
int queue_empty(queue *);
int queue_full(queue *);

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
				if(queue_full(&Q)){
					printf("Queue is full\n");
				}else{
					printf("Enter data :\n");
					scanf("%d",&data);
					enqueue(&Q,data);
					printf("%d is added in the queue\n",data);
				}
				break;
			case 2:
				if(queue_empty(&Q)){
					printf("Queue is empty\n");
				}else{
					int ele = get_front(&Q);
					dequeue(&Q);
					printf("%d is removed from queue\n",ele);
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

void enqueue(queue *pq ,int data){
	pq->rear = ((pq->rear)+1) % SIZE;
	pq->arr[pq->rear] = data;

	if(pq->front == -1){
		pq->front++;
	}
}

void dequeue(queue *pq){

	if(pq->front == pq->rear){
		pq->front = pq->rear = -1;
	}else{
	pq->arr[pq->front] = 0;
	pq->front = (pq->front+1)%SIZE;
	}
}

int get_front(queue *pq){
	return pq->arr[pq->front];
}

int queue_empty(queue *pq){
	return pq->rear == -1;
}

int queue_full(queue *pq){
	return pq->front == ((pq->rear+1)% SIZE);
}

//int display(queue* pq){

//}
