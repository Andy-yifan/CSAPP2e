#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


#define VECTOR_SIZE 10000000
typedef long long data_t;
typedef data_t *vec_ptr;

data_t *get_vec_start(vec_ptr v) {
	return v;
}

int vec_length(vec_ptr v) {
	return VECTOR_SIZE;
}


void inner4(vec_ptr u, vec_ptr v, data_t *dest) {
	
	long int i;
	int length = vec_length(u);
	int newlen = length - 3;
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	
	data_t sum_0 = (data_t) 0;
	data_t sum_1 = (data_t) 0;
	data_t sum_2 = (data_t) 0;
	data_t sum_3 = (data_t) 0;
	
	for(i = 0; i < newlen; i+=4){
		sum_0 += udata[i] * vdata[i];
		sum_1 += udata[i+1] * vdata[i+1];
		sum_2 += udata[i+2] * vdata[i+2];
		sum_3 += udata[i+3] * vdata[i+3];
	}
	
	for (i = 0; i < length; i++) {
		sum_0 = sum_0 + udata[i] * vdata[i];
	}
	*dest = sum_0 + sum_1 + sum_2 + sum_3;
}


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