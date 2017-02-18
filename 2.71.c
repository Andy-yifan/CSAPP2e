#include <stdio.h>

typedef unsigned packed_t;

/* Failed attempt at xbyte */
/* int xbyte(packed_t word, int bytenum)
   {
	   return (word >> (bytenum << 3)) & 0xFF;
   }*/
   
/* A. Above code just can deal with positive number, and it 
cannot process negation number in the result completely which 
is A to F. since packet_t is unsign*/

/* B. Following function is correct implementation that uses only
left and right shifts with one subtraction. */
int xbyte(packed_t word, int bytenum){
	
	// how many bits should shift.
	int shift_bits = (3 - bytenum) << 3;
	// move the input word
	int left_byte = word << shift_bits;
	// sign byte into 32-bit which right shift 3*8
	int signed_byte = left_byte >> 24;
	return signed_byte;
    
	
}

int  main(void){
	
	printf("0x%X\n", xbyte(0x11223344, 3));
	printf("0x%X\n", xbyte(0x11223344, 2));
	printf("0x%X\n", xbyte(0xAABBCCDD, 0));
	printf("0x%X\n", xbyte(0xAABBCCDD, 2));
	
}
