#include <stdio.h>
#define SIZE 9
#define SWAP(a,b) {int temp =a; a = b; b = temp;}

void selection_sort(int []);
void selection_sort_rev(int []);

int main(void){
    int arr[SIZE] = {11,49,45,90,45,22,44,45,60};

    printf("Before sorting :");
    for(int i=0; i< SIZE; i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
    selection_sort(arr);
    printf("\n");
    printf("After sorting : ");
    for(int i=0; i<SIZE; i++){
        printf("%4d",arr[i]);
    }

    selection_sort_rev(arr);

    printf("Desending Order : ");
    for(int i=0; i<SIZE; i++){
        printf("%4d",arr[i]);
    }
}

void selection_sort(int arr[]){
    for(int i=0;i<SIZE-1;i++){
        for(int j=i+1;j< SIZE;j++){
            if(arr[i] > arr[j]){
                SWAP(arr[i],arr[j]);
                // int temp = arr[i];
                // arr[i]  = arr[j];
                // arr[j] = temp;
            }
        }
    }
}

// Decending order 

void selection_sort_rev(int arr[]){
    for(int i=0;i<SIZE-1;i++){
        for(int j=i+1;j< SIZE;j++){
            if(arr[i] < arr[j]){
                SWAP(arr[i],arr[j]);
            }
        }
    }
}