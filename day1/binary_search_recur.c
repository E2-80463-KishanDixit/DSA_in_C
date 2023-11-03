#include<stdio.h>
#define SIZE 9

int binary_search_recur(int [],int, int ,int);

int main(void){
    int key;
    int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
    printf("Enter key \n");
    scanf("%d",&key);

    int index = binary_search_recur(arr,key,0,SIZE-1);

    if(index != -1)
        printf("Key= %d is present at index = %d", key,index);
    else{
        printf("Key not found");
    }
}


int binary_search_recur(int arr[],int key,int strt, int end){
    int mid = (strt + end)/2;

    if(end<strt)
        return -1;
    if(key == arr[mid])
        return mid;
    else if(key > arr[mid]){
        binary_search_recur(arr,key,mid+1,end);
    }else if(key < arr[mid]){ 
        binary_search_recur(arr,key,strt,mid-1);
    }
}