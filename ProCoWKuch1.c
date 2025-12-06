#include<stdio.h>

void TowerOfHanoi( int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from %c to rod %c", from, to);
        return ;
    }
    
    TowerOfHanoi(n-1, from, aux, to);
    printf("\nN1 = %d",n);
    printf("\nMove disk %d from rod %c to rod %c", n, from, to);
    printf("\nN2 = %d",n);
    TowerOfHanoi(n-1, aux, to, from);
}

int main()
{
    int n = 3;
    TowerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}