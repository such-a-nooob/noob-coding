#include<stdio.h>
#include<conio.h>
void main()
{
int a[10],n,f=0;
clrscr();
printf("\nEnter the number of terms "); scanf("%d",&n);
printf("\nEnter %d numbers in array ",n);
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
if(a[i]<a[i+1]) f++;
if(f==n)
printf("\nArray is sorted ");
else
printf("\nArray is not sorted ");
getch();
}