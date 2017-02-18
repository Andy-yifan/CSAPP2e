#include <stdio.h>
#include <string.h>
/* Copy integer into buffer if space is available */
/* WARNING: The following code is buggy */
/*
void copy_int(int val, void *buf, int maxbytes){
	
	if (maxbytes-sizeof(val) >= 0){
		
		memcpy(buf, (void *) &val, sizeof(val));
		
	}
		
} 
*/

/* A. The sizeof function will always return unsigned, and valuemaxbytes-sizeof(val) will become unsigned minus, the result always positive and always true.therefore the code always succeeds.
*/

/* B. add one more condition which let
the maxbytes greater than 0. */

void copy_int(int val, void *buf, int maxbytes){
	 if (maxbytes >= sizeof(val)) {
        printf(" int placed in buffer.\n");
        memcpy(buf, (void *) &val, sizeof(val));
    }else{
    	printf(" int overload!\n");
    }
		
} 

int main(){
    int a = 3;	
	int array[5];

	copy_int(a, array, 5);	//this should get in to the if statement
	copy_int(a, array, 3);	//this should FAIL to get in to the if statement
	return 0;
}
	

