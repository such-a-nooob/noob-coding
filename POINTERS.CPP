/*linear search using pointers*/
#include<stdio.h>
#include<conio.h>
void main()
{
int a[50],n,x,i,*p,px,f=0;
clrscr();
printf("\nEnter the number of terms\t");
scanf("%d",&n);
printf("\nEnter %d numbers in array\n",n);
for(i=0;i<n;i++)
scanf("%d",p+i);
printf("\nEnter a number to be searched\t");
scanf("%d",&x);
for(i=0;i<n;i++)
if(*(p+i)==x)
{ f=1; px=i; break;}
if(f==1)
printf("\n %d is found at position %d ",x,px+1);
else
printf("\n %d is not found ",x);
getch();
}

