//smallest number in array using pointers
#include<stdio.h>
#include<conio.h>
int small(int*a,int n);
void main()
{
int a[50],n;
printf("\nEnter no. of elements in array ");
scanf("%d",&n);
printf("\nEnter %d no. in array ",n);
for(int i=0;i<n;i++)
scanf("%d",(a+i));
int sm=small(a,n);
printf("\nSmallest number= %d",sm);
getch();
}
int small(int*a,int n)
{
int s;
s=*(a+0);
for(int i=0;i<n;i++)
{
if(*(a+i)<s)
s=*(a+i);
}
return s;
}

