// Address change by pointer. 

#include<stdio.h>
int main()
{
    int *p;
    int a = 10;
    p = &a;
    printf("%u\n", p);
    p += 1;
    printf("%u\n", p);
    
    return 0;
}