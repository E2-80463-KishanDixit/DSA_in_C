#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * head = NULL;
struct node * create_node(int);
// TAIL TO DO OPERATION FROM THE LAST OF THE LIST
// struct node * tail = NULL;

// ADD NODE AT FIRST POSTION
void add_first(int);
// DISPLAY THE ALL NODES 
void display(void);
// ADD NODE AT LAST
void add_last(int);
// ADD NODE AT SPECTIFIC POSITION
void add_at_position(int,int);
// COUNT THE ALL PRESENT NODES
int count_node(void);
// DELETE FIRST NODE
void delete_first(void);
// DELETE LAST NODE 
void delete_last(void);
// DELETE NODE AT A SPECIFIC POSITION
void delete_at_position(int);

int main(void){
    add_first(10);
    add_first(20);
    add_first(30);
    add_first(40);
    add_first(50);

    add_last(100);

    add_at_position(500,3);

    delete_first();

    delete_last();

    delete_at_position(1);
    
    display();
    return 0;
}

struct node * create_node(int data){
    //create node   
    struct node * ptr = (struct node *)malloc(sizeof(struct node));

    if(ptr == NULL){
        printf("Oops !! Malloc Faliled !!");
    }
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void add_first(int data){
    
    struct node * ptr = create_node(data);

    if(head == NULL){
        head = ptr;
    }else{
        ptr->next = head;
        head = ptr;
    }
}

void display(void){
    if(head == NULL){
        printf("Linked List is empty\n");
    }else{
        struct node * trav = head;
        printf("head");
        while(trav != NULL){
            printf("-> %d ",trav->data);
            trav = trav->next;
        }
    }
}

void add_last(int data){
    struct node * ptr = create_node(data);

    if(head == NULL){
        add_first(data);
    }else{
        struct node * trav = head;
        while(trav->next != NULL){
            trav = trav->next;
        }
        trav->next = ptr;
        // LAST NODE ADDRESS PTR
        // struct node * tail =  ptr;
    }
}

void add_at_position(int data,int pos){

    if(head == NULL){
        if(pos == 1){
            add_first(data);
        }else{
            printf("List is empty!!");
        }
    }else if(pos == 1){
        add_first(data);
    }else if(pos == (count_node()+1)){
        add_last(data);
    }else if(pos < 1 || pos > count_node()+1){
        printf("Invalid Position!! ");
    }else{
        struct node * ptr = create_node(data);
        struct node * trav = head;
        int i = 1;
        while(i<pos-1){
            trav = trav->next;
            i++; 
        }
        ptr->next = trav->next;
        trav->next = ptr;
    }
}

int count_node(){
    int count = 0;
        struct node * trav = head;
        while(trav != NULL){
            trav = trav->next;
            count++;
        }
        return count;
}

void delete_first(void){
    struct node * temp = NULL;
    temp = head->next;
    free(head);
    head = temp;
}

void delete_last(void){
    struct node * trav  = head;

    while(trav->next->next != NULL){
        trav = trav->next;
    }
    free(trav->next);
    trav->next = NULL;
}

void delete_at_position(int pos){
    if(head == NULL){
        printf("List is empty\n");
    }else if(pos == 1){
        delete_first();
    }else if(pos == count_node()+1){
        delete_last();
    }else{
            struct node * trav = head ;
            for(int i=1;i<pos-1;i++){
                trav = trav->next;
            }
            struct node * temp = trav->next->next;
            free(trav->next);
            trav->next = temp;
    }
}
