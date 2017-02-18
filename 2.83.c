#include <stdio.h>

unsigned f2u(float x){
    return *((unsigned*)(&x));
}

int float_le(float x,float y){
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (!sx && !sy && ux <= uy) || // x>=0, y>=0
    (sx && sy && ux >= uy) || // x<0 y<0
    ((ux << 1) == 0 && (uy << 1) == 0) ||// all zero
    (sx && !sy);// x>= 0 y<0
    
}

int main(){
  printf("%d\n",float_le(10.6,9.4));//retrun 0
  printf("%d\n",float_le(-12.6,-7.5));//retrun 1
  printf("%d\n",float_le(5.4,-6.2));// return 0
  printf("%d\n",float_le(55,55.0));//return 1
}
