/*Write code to implement the following function:
 Return 1 when any odd bit of x equals 1; 0 otherwise.
 Assume w=32. 
int any_odd_one(unsigned x);
*/

#include <stdio.h>

int any_odd_one(unsigned x){
    //meet the requirement of inter coding rules
    int y = 0xAAAAAAAA;//32bit all even bits =1
    return (x & y)!=0;
}

int main(){
	
	int i = any_odd_one(0x55555555);
	printf("is it any odd one? for 0x55555555 %i\n",i);
    
    int b = any_odd_one(0xFFFFFFFF);
    printf("is it any odd one? for 0xFFFFFFFF %i\n",b);

    int c = any_odd_one(0x03);
    printf("is it any odd one? for 0x03  %i\n",c);
	
}



