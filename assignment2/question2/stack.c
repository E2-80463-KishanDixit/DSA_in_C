#include <stdio.h>
#include <stdlib.h>

struct stack{
    int * ptr;
    int top;
    int size;
}stack;

void stack_init(struct stack *);
void push(struct stack * ,int);
void pop(struct stack *);
int top(struct stack *);
void display(struct stack *);

int main(void){
    struct stack stk;

    stack_init(&stk);
    push(&stk,10);
    push(&stk,20);
    push(&stk,30);
    push(&stk,40);
    // pop(&stk);
    display(&stk);
    return 0;
}

void stack_init(struct stack *stk){
    printf("Enter the size of stack\n");
    scanf("%d",&stk->size);

    stk->ptr = (int*)malloc(sizeof(int)*stk->size);
    if(stk-> ptr == NULL){
        printf("Malloc failed!! ");
        return;
    }
    stk->top = -1;
}

void push(struct stack * stk,int data){
    
    if(stk->size == stk->top){
        printf("Stack is full !!");
        return;
    }
    stk->top++;
    stk->ptr[stk->top] = data;
}

void pop(struct stack * stk){

    if(stk->top == -1){
        printf("Stack is empty!! ");
        return ;
    }
    stk->ptr[stk->top] = 0;
    stk->top--;
}

int top(struct stack * stk){
    return stk->top;
}

void display(struct stack * stk){
    for(int i = stk->top;i>=0;i--){
        printf("%4d",stk->ptr[i]);
    }
}