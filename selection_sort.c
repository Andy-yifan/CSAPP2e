#include <stdio.h>
#include <stdlib.h>

// the selection sort source is form https://github.com/KingCoolS520/MyRepos/blob/386c43befc97d3b61a643cb55cbb1707f0ebf22b/2.%E6%8E%92%E5%BA%8F__all/%E6%8E%92%E5%BA%8F/demo01_%E9%80%89%E6%8B%A9%E6%8E%92%E5%BA%8F.c
void SelectionSort(int *array, int len)
{
	int min = 0;	
	for (int i = 0; i < len - 1; ++i){
		min = i;
		for (int j = i + 1; j < len; ++j){
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (min != i){
			int tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
		}
	}
}


int main(void){
	
	int i;
	int size;
	int l;
	int *array;
	int number = 0;
	
	
	printf("Please enter the length of the array: \n");
	scanf("%d", &size);
	array = malloc( sizeof(int) * size );
	
	for (i = 0; i < size; i++){
		printf("Please enter an integer for array element: \n");
		scanf("%d", &number);
		array[i] = number;
		
	}
	SelectionSort(array, size);
	
	printf("Sorted contents of array is: \n");
	for (i = 0; i < size; i++) {
		
		printf("%d\n",array[i]);
		
	}
	//free the memory
	free(array);
	
}
