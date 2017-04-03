#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define VECTOR_SIZE 8
typedef long long data_t;

typedef data_t *vec_ptr;
data_t *get_vec_start(vec_ptr v) {
	return v;
}

//Function to return vector length
int vec_length(vec_ptr v) {
	return VECTOR_SIZE;
}


//Accumulate in temporary
void inner4(vec_ptr u, vec_ptr v, data_t *dest) {
	long int i;
	int length = vec_length(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum = (data_t) 0;

	for (i=0; i<length; i++) {
		sum = sum + udata[i] * vdata[i];
	}
	*dest = sum;
}


//source for main part：https://github.com/connorworkman/uo-repo/blob/af80e9691724f3a749b523bbc93ca2ee0a619873/2014FALL/cis314/assignment4/5.15.c
int main() {
    clock_t start, end;
    double cpu_time_used;
    int i;
	data_t* u;
	u = (data_t*)calloc(VECTOR_SIZE,sizeof(data_t));
        data_t* v;
	v = (data_t*)calloc(VECTOR_SIZE,sizeof(data_t));

	for (i=0; i<VECTOR_SIZE; i++) {
		u[i] = i+1;
		v[i] = i+1;
	}

	start = clock();	
	vec_ptr a = u;
    vec_ptr b = v;
    data_t *p = malloc(sizeof(data_t));
    inner4(u,v,p); 
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n",cpu_time_used);
}
