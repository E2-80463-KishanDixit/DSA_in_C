#include <stdio.h>
#define SIZE 9
#define SWAP(a,b) {int temp = a; a = b; b = temp;}

void insertin_sort(int []);
void display(int []);

int main(void){
    int arr [SIZE] = {3,5,67,23,12,20,19,30,34};

    printf("Before sorting :");
    display(arr);
    printf("\n");
    insertin_sort(arr);
    printf("After sorting :");
    printf("\n");
    display(arr);

    return 0;
}

void insertin_sort(int arr[]){
    int temp=0,flag =0;
    for(int i=1;i< SIZE ;i++){
        int j;
        for(j= i-1;j>=0;j--){
            if(arr[j] > arr[i]){
                temp = arr[i];
                arr[j+1] = arr[j];
                flag =1;
            }
        }
        if(flag == 1){
            arr[j+1] = temp;
        }
    }
}

void display(int arr[]){
    for(int i=0; i< SIZE;i++){
        printf("%4d ",arr[i]);
    }
}