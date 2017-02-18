/*] B&O’H 2.68.
Write code for a function with the following prototype:

* Mask with least signficant n bits set to 1
* Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
* Assume 1 <= n <= w

int lower_one_mask(int n);
Your function should follow the bit-level integer coding rules (page 120). Be careful of
the case n = w. 
*/
#include <stdio.h>


int lower_one_mask(int n){
    //since when n =w will get error if (1<<n)-1
    int x = (1 << (n-1)) - 1;
    return (x << 1) + 1;
}

int main(){
    printf("0x%X\n",lower_one_mask(6));
	printf("0x%X\n", lower_one_mask(17));
    printf("0x%X\n", lower_one_mask(1));
    printf("0x%X\n", lower_one_mask(3));
    

}
