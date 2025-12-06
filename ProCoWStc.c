// Structure use.

#include<stdio.h>
struct Link
{
    int data;
    char nm[20];
};
struct Link obj[10];

int main()
{
    int i;
    for ( i = 0; i < 5; i++)
    {
       printf("Name = ");
       scanf("%s",obj[i].nm);
       printf("Data = ");
       scanf("%d",&obj[i].data);
    }
    for ( i = 0; i < 5; i++)
    {
        printf("Name = %s\tData = %d\n", obj[i].nm , obj[i].data);
    }
    return 0;
}
