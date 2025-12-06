// Program for find number is Prime OR not by create function.
#include<stdio.h>
void Prm(int a[], int s)
{
  int k = 0;
  for (int i = 0; i <= s; i++)
  {
    for (int j = 1; j < a[i]; j++)
    {
     if (a[i]%j == 0)
      {
        ++k;
      }
    }
    if (k == 2)
    {
      printf("\n%d is prime.", a[i]);
    }
      
  }
    
}
int main()
{
   int a[100], i, n, idx, s = 100;
   printf("Enter the size:- ");
   scanf("%d", &n);
   idx = n - 1;
   printf("\nEnter element\n");
   for (i = 0; i < n; i++)
   {
     scanf("%d", &a[i]);
   }
   Prm(a,idx);
   return 0;
}