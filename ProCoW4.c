#include<stdio.h>
int main()
{
    int *p;
    int a[] = {1, 2, 3, 4, 5};
    int sum = 0;
    p=a;
    for(int i = 0; i < 5; i++)
    {
        if(i%2 == 0)
        {
            sum += *(p+i);
        }else
        {
            sum -= *(p+i);
        }
        
    }
    printf("%d", sum);
    return 0;
}