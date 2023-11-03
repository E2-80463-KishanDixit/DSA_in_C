#include <stdio.h>
#define SIZE 9

void insertion_sort(int []);
void display(int []);

int main(void){
	int arr[SIZE] = {11,66,33,99,35,23,78,56,34};
	printf("\nBefore Sorting\n");
	display(arr);
	insertion_sort(arr);
	printf("\nAfter sorting:\n");
	display(arr);
	return 0;
}


void insertion_sort(int arr[]){
	int i,j,temp;


	for(i = 1; i <SIZE; i++){
		temp = arr[i];
		for(j = i-1; j>=0 && arr[j] > temp ;j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
	}
}

void display(int arr[]){
	for(int i=0;i< SIZE; i++){
		printf("%4d ",arr[i]);
	}
}
