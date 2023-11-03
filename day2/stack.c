#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct stack{
	int arr[SIZE];
	int top;
	int count;
}stack;

void stack_init(stack *);
void push(stack *,int );
void pop(stack *);
int  peak(stack *);
int count(stack *);


int main(void){
	int choice;
	int data;
	stack stk;
	stack_init(&stk);

	do{
		printf("Enter Your choice\n");
		printf("0.Exit\n1.push data on stack\n2.pop data from stack\n3.to see top of stack\n4.Element count in stack\n");
		scanf("%d",&choice);

		switch(choice){
			case 0:
				exit(0);
			case 1:
				if(stk.top == SIZE-1){
					printf("Stack is full\n");
				}else{
					printf("\nEnter data\n");
					scanf("%d",&data);
					push(&stk,data);
					printf("Data pushed\n"); 
				}
				break;
			case 2:
				if(stk.top == -1){
					printf("\nStack is Empty\n");
				}else{
					pop(&stk);
					printf("data poped\n");
				}
				break;
			case 3:
				printf("\n %d elements present in stack\n",peak(&stk));	
				break;
			case 4:
				printf("\n %d elements present in stack\n",stk.count);
				break;
			default:
				printf("Enter valid choice!!!!!\n");
		}
	}while(choice!=0);
	

	
	return 0;
}

void stack_init(stack *stk){
	stk->top = -1;
	stk->count = 0;
}

void push(stack *stk,int data){
	(stk->top)++;

	stk->arr[stk->top] = data;
	(stk->count)++;
}

void pop(stack *stk){
	stk->arr[stk->top] = 0;
	(stk->top)--;
	(stk->count)--;
}

int peak(stack *stk){
	return stk->arr[stk->top];
}

int count(stack *stk){
	return stk->count;
}


