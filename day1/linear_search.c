#include <stdio.h>
#define SIZE 9

int linear_search(int [],int);

int main(void){
    int key;
    int arr[SIZE] = {11,55,33,77,88,22,44,99,66};
    printf("Enter a number ");
    scanf("%d",&key);

    int index = linear_search(arr,key);
    if(index!= -1)
        printf("Key = %d is present at %d ",key,index);  
    else
        printf("Key not found"); 
    return 0;
}

int linear_search(int arr[],int key){
    for(int i=0;i<SIZE;i++){
        if(key == arr[i]){
            return i;
        }
    }
    return -1;
}