#include <stdio.h>
#include <stdlib.h>

struct Block{
	unsigned char valid;
	unsigned int tag;
	unsigned int value;
	
};

unsigned int getSetNumber(unsigned int address){
	//return the set number
	return (address & 0x3F) >> 2;
}

unsigned int getOffset(unsigned int address){
	//return the offset
	return address & 0x3;
}

unsigned int getTag(unsigned int address){
	//return the tag value
	return address >> 6;
}
//source:https://github.com/adamcarlton/codeprojects/blob/eac51fe4b401d192fe1fde96f9039a91c26038d3/C%26C%2B%2B%20projects/Cproj8
int main(){
	//struct Block *cache = struct 16 cache block
	struct Block *cache = malloc(16);
	
	for (unsigned int i; i < 16; i++){
		cache[i].valid = 0;
	}
	
	char c;
	int flag = 1;
	while(flag){
		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit:");
		
		scanf(" %c", &c);
		
		if (c == 'r') { //if read, equal to 'r'
			printf("Enter 32-bit unsigned hex address: ");
			
			unsigned int a;
			scanf("%x", &a);
			
			unsigned int setNumber = getSetNumber(a);
			unsigned int offset = getOffset(a);
			unsigned int tag = getTag(a);
			
			printf("looking for set: %x - tag: %x \n" , setNumber, tag);
			
			struct Block * block = &cache[setNumber];
			
			if (block->valid == 1) { //block is valid
				// retrieve the block value;
				// print out all info
				unsigned int value = block->value >> 8 * offset & 0xFF;
				unsigned int tagTwo = block->tag;
				printf("found set: %x - tag: %x - offset:%x - valid: 1 - value: %x \n", setNumber, tagTwo, offset, value);
				if(tagTwo == tag) {
                    //tag match
					printf("hit!\n");
				} else {
					printf("tags don't match - miss!\n");
				}
			} else {
				printf("no valid set found - miss!\n");
			}
			
		}else if(c == 'w') { //if write, equal to 'w'
			unsigned int a;
			unsigned int v;
			
			printf("Enter 32-bit unsigned hex address: ");
			scanf(" %x", &a); //get the address
			
			printf("Enter 32-bit unsigned hex value: ");
			scanf(" %x", &v); //get the value
			
			unsigned int setNumber = getSetNumber(a);
			unsigned int tag = getTag(a);
			
			struct Block * block = &cache[setNumber];
			
			if (block -> valid == 1) {
				//retrieve the current block value;
				//print out all info of the evicting block;
				unsigned int value = block->value;
				unsigned int tagTwo = block->tag;
				unsigned int one = value >> 24 & 0xFF;
				unsigned int two = value >> 16 & 0xFF;
				unsigned int three = value >> 8 & 0xFF;
				unsigned int four = value & 0xFF;
				printf("evicting block - set: %x - tag: %x - valid: 1 - value %x %x %x %x\n", setNumber, tagTwo,  four , three, two, one);
				
			}
			block -> value = v;
			block -> tag = tag;
			block -> valid = 1;
			//return the value we write;
			//print out all info;
			unsigned int one = v >> 24 & 0xFF;
			unsigned int two = v >> 16 & 0xFF;
			unsigned int three = v >> 8 & 0xFF;
			unsigned int four = v & 0xFF;
			printf("wrote set: %x - tag: %x - valid: 1 - value: %x %x %x %x \n", setNumber, tag, four , three, two, one);
			
		}else if(c == 'p') {
            //if print, equal to 'p'
			for(int i = 0; i < 16; i++){
				struct Block * block = &cache[i];
				if(block -> valid == 1) {
                    //block is valid
					//retrieve the value of current blovk
					//print out all info
					unsigned int v = block -> value;
					unsigned int one = v >> 24 & 0xFF;
					unsigned int two = v >> 16 & 0xFF;
					unsigned int three = v >> 8 & 0xFF;
					unsigned int four = v & 0xFF;
					printf("set: %x - tag: %x - valid: 1 - value: %x %x %x %x \n", i, block->tag, four,three, two, one);
				}
			}
		}
		else if(c == 'q'){
			flag= 0;
		}
		else{// other input, quit.
    		printf("Invalid input. Quit this simulation \n");
    		flag = 0;
    	}
	}

    
}