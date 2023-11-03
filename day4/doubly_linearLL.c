#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * head = NULL;
node * tail = NULL;

node * create_node(int);
void add_first(int);
void display_forword(void);
void display_backword(void);
void add_last(int);
void delete_first(void);
void delete_last(void);
int count_nodes(void);
void add_at_pos(int, int);
void delete_at_pos(int);


int main(void){
    add_first(10);
    add_first(20);
    add_first(30);
    add_first(40);
    add_first(50);
    // add_at_pos(500,4);
    delete_at_pos(2);
    // delete_first();
    // delete_last();
    // add_last(500);
    display_forword();
    printf("\n");

    display_backword();
    return 0;
}

node * create_node(int data){
    node * new_node = (node *)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Malloc Failed !!!\n");
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void add_first(int data){
    node * new_node = create_node(data);
    if(head == NULL){
        head = new_node;
        tail = new_node;
    }else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void display_forword(void){
    node * trav = head;
    printf("head");
    while(trav != NULL){
        printf("->%d" ,trav->data);
        trav = trav->next;
    }
}

void display_backword(void){
    node * trav = tail;
    printf("tail");
    while(trav!= NULL){
        printf("->%d",trav->data);
        trav = trav->prev;
    }
}

void add_last(int data){
    if(head == NULL){
        add_first(data);
    }else{
        node * new_node = create_node(data);
        // make connection
        new_node->prev = tail; 
        tail->next = new_node;
        // break connection
        tail = new_node;
    }
}

void delete_first(void){
    if(head == NULL){
        printf("List is empty.Nothing to delete!!\n");
    }else{
        node * temp = head;
        head->next->prev = NULL;
        head = head->next;
        free(temp);
    }
}

void delete_last(void){
    if(head == NULL){
        printf("List is empty.Nothing to delete!!\n");
    }else{
        node * temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        // break the connection
        free(temp);
    }
}

int count_nodes(void){
    int count = 0;
    node* trav = head;

    while(trav != NULL){
        trav = trav->next;
        count++;
    }
    return count;
}

void add_at_pos(int data, int pos){
    if(head == NULL){
        add_first(data);
    }else if(pos == count_nodes()+1){
        add_last(data);
    }else if(pos < 1 || pos > count_nodes()+1){
        printf("Invalid Position\n");
    }else{
        node * new_node = create_node(data);
        node * trav = head;
        for(int i=1 ; i<pos-1; i++){
            trav = trav->next;
        }
        new_node->next = trav->next;
        new_node->prev = trav;
        trav->next->prev = new_node;
        trav->next = new_node;
    }
}

void delete_at_pos(int pos){
    node * trav = head;
    if(head == NULL){
        printf("List is empty. Nothing to delete!!\n");
    }else if(pos == 1){
        delete_first();
    }else if(pos == count_nodes()+1){
        delete_last();
    }else{
        node * trav = head;
        for(int i=1;i<pos-1;i++){
            trav = trav->next;
        }
        node * temp = trav->next ;
        trav->next = trav->next->next;
        trav->next->prev = trav;
        free(temp);
    } 
}

