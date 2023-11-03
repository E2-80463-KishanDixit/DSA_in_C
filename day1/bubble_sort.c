#include <stdio.h>
#define SIZE 9
#define SWAP(a,b) {int temp = a; a = b; b = temp;}

void bubble_sort(int []);
void display(int []);

int main(void){
    int arr [SIZE] = {3,5,67,23,12,20,19,30,34};

    printf("Before sorting :");
    display(arr);
    printf("\n");
    bubble_sort(arr);
    printf("After sorting :");
    printf("\n");
    display(arr);


    return 0;
}

void bubble_sort(int arr[]){
    int flag;
    for(int i=0;i< SIZE-1;i++){
        flag =0;
        for(int j=0;j< SIZE-1-i; j++){
            if(arr[j] > arr[j+1]){
                SWAP(arr[j],arr[j+1]);
                flag =1;
            }
        }
        if(flag == 1)
            break;
    }
}

void display(int arr[]){
    for(int i=0; i< SIZE;i++){
        printf("%4d",arr[i]);
    }
}