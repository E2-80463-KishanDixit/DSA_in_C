#include<stdio.h>
#define SIZE 9

int binary_search(int [],int);

int main(void){
    int key;
    int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
    printf("Enter key \n");
    scanf("%d",&key);

    int index = binary_search(arr,key);

    if(index != -1)
        printf("Key= %d is present at index = %d", key,index);
    else{
        printf("Key not found");
    }
}

int binary_search(int arr[],int key){
    int mid;
    int start =0;
    int end = SIZE-1;

    while(start <=  end)
    {
        mid = (start+end)/2;
        if(key == arr[mid]){
            return mid;
        }
        else if(key < arr[mid]){
            end = mid-1;
        }else if(key > arr[mid]){
         start = mid+1;
        }
    }
    return -1;
}