/* Write a C program which:
• Prompts the user for an integer array length.
• Uses the malloc() function to allocate the array.
• Prompts the user to enter an integer for each array element.
• Sorts the array in ascending order using Selection Sort.
• Prints the sorted contents of the array.
• Frees the memory allocated for the array using the free() function.
*/

#include <stdio.h>
#include <stdlib.h>

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
