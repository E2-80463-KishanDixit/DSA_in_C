#include "header.h"

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
