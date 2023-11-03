#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node * head = NULL;

node * create_node(int);
void add_first(int);
void display(void);
void add_last(int);
void delete_first(void);
void delete_last(void);

int main(void){
    // add element at first 
    add_first(10);
    add_first(20);
    add_first(30);
    add_first(40);

    // add element at last
    add_last(60);
    add_last(70);
    add_last(80);

    // delete element at first
    delete_first();
    delete_first();

    // delete element at last
    delete_last();
    delete_last();
    display();
    return 0;
}

node * create_node(int data){
    node * new_node = (node *)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Malloc Failed!! ");
    }else{
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

void add_first(int data){
    node * new_node = create_node(data);
    if(head == NULL){
        head = new_node;
        new_node->next = head;
    }else{
        node* trav = head;
        while(trav->next != head){
            trav = trav->next;
        }
        new_node->next = head;
        head = new_node;
        trav->next = head;
        // or     trav->next = new_node;
        trav = NULL;
    }
}

void display(void){
    node * trav = head;
    if(head == NULL){
        printf("List is Empty!!\n ");
    }

    printf("head");
    do{
        printf("->%d",trav->data);
        trav = trav->next;
    }while(trav != head);
    printf("\n");
}

void add_last(int data){
    if(head == NULL){
        add_first(data);
    }else{
        node * new_node = create_node(data);
        node * trav = head;
        while(trav->next != head){
            trav = trav->next;
        }
        trav->next = new_node;
        new_node->next = head;
    }
}

void delete_first(void){
    if(head == NULL){
        printf("Opps List is Empty!! Nothing to delete. \n");
    }else if(head->next == head){
        free(head);
        head = NULL;
    }else{
        node * trav = head;
        while(trav->next != head){
            trav = trav->next;
        }

        node* temp = head;
        head = temp->next;
        trav->next = head;
        //or trav->next = temp->next;
    }
}

void delete_last(void){
    if(head == NULL){
        printf("List is Empty. Nothing to delete!!\n");
    }else if(head->next == head){
        delete_first();
    }else{
        node * trav = head;

        while(trav->next->next != head){
            trav = trav->next;
        }
        node * temp = trav->next;
        trav->next = head;
        free(temp);
        trav = NULL;
    }

}