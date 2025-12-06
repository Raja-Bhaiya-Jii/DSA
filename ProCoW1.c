#include<stdio.h>
int main()
{
    void *p;
    int a = 10;
    char ch = 'a';
    float f = 30.3;
    p = &a;  // assignment
    printf("%d\n", *(int*)p);           //De-refrenceing Process
    p = &ch;
    printf("%c", *(char*)p);
    p =&f;
    printf("\n%f", *(float*)p);
    return 0;
}