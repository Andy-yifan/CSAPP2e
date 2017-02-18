//B&O’H 2.57.
//Write procedures show_short, show_long, and show_double that print the byte
//representations of C objects of types short int, long int, and double, respectively. Try
//these out on several machines. 

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
    int i;
    for (i = 0; i < len; i++){
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_short(short int x){
	
    show_bytes((byte_pointer) &x, sizeof(int));
	
}

void show_long(long int y){
	
    show_bytes((byte_pointer) &y, sizeof(int));
	
}

void show_double(double z){
	
    show_bytes((byte_pointer) &z, sizeof(double));
	
}

int main(void){
	
	short int sh_int =  1;
	long int lg_int =  10;
	double dou_num =  2.5;
	
	show_short(sh_int);
	show_long(lg_int);
	show_double(dou_num);
}
