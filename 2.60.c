/*Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 − 1 (most
significant). Write code for the following C function, which will return an unsigned value
in which byte i of argument x has been replaced by byte b:
unsigned replace_byte (unsigned x, int i, unsigned char b);
Here are some examples showing how the function should work:
replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
*/

#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){
	
	//move b which 0xAB to the left for i * 8 bits.
	unsigned pos = b<<(i<<3);
	
	//move the mask to left for same bits with b.
	//then get the reverse of the mask.
    unsigned new = ~(0xFF<<(i<<3));

	
	//return the rest of bytes except mask and bombine
    return (x&new)|pos;
	
}

int main(void){

    printf("0x%X\n", replace_byte(0x12345678, 2, 0xAB));
    printf("0x%X\n", replace_byte(0x12345678, 0, 0xAB));
	
}
