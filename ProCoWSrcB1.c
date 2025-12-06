// Program of Binary Search.

#include<stdio.h>

int a[100], n = 100, st = -1, lt = -1, mid, i = -1, src;

void BSrc();
void Create();

int main()
{
    int ch = 0;

    do
    {
      printf("\n1. Create");
      printf("\n2. Search");
      printf("\nEnter: ");
      scanf("%d",&ch);

    
      switch (ch)
      {
      case 1:
         Create();
         break;
      
      case 2:
         printf("\nEnter Value: ");
         scanf("%d",&src);
         st = 0;
         lt = i;
         BSrc(a, src , st , lt);
         break;
    
      default:
         ch = 0;
        break;
      }  
    } while (ch != 0);
    
}


void Create()
{
    int ch;

    st = 0;
    
    do
    {
        i++;
        printf("\nEnter Value %d: ",i+1);
        scanf("%d",&a[i]);

        lt = i;

        printf("\nFor Continue, Press 1: ");
        scanf("%d",&ch);

        
    } while (ch != 0);

     for (size_t j = 0; j <= lt-1; j++)             // Bubble Sorting.
        {
           for (size_t k = 0; k < lt-j; k++)
           {
              if (a[k] > a[k+1])
              {
                 int temp = a[k];
                 a[k] = a[k+1];
                 a[k+1] = temp;
              }   
           }
           
        }  
        
     for (size_t j = 0; j <= lt; j++)             
            printf("\n%d",a[j]);
        
}

void BSrc(int a[], int value, int lp, int rp)
{
   int point;
   point = (lp+rp)/2;

   if (value == a[point])
   {
      printf("\n%d is found.",value);
   }else if (value > a[point])
   {
      BSrc(a, value , point+1, rp);
   }else if (value < a[point])
   {
      BSrc(a, value, lp , point-1);
   }
   
   if (lp > rp)
   {
      printf("\n%d is not found.",value);
   }
   
   
}