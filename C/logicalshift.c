#include<stdio.h>
#include<math.h>

int shift(int x , int n)
{
    unsigned int mask = ~0U >> n;  // Create a mask of 1's with n trailing 0's
    return (x >> n) & mask;
}
	

void main(int argc , char* argv[])
{

    int x , n;

    sscanf(argv[1] , "%d" , &x);
    sscanf(argv[2] , "%d" , &n);

    printf("After Logical Shift : %d \n" , shift(x , n));
}
