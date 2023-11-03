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