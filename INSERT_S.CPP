/*insertion sort*/
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
int a[50],i,j,n,t,m,c;
clrscr();
printf("\n Enter the number of terms in array ");
scanf("%d",&n);
printf("\n Enter %d terms in array\n",n-1);
for(i=1;i<n;i++) scanf("%d",&a[i]);
printf("\nWant to see Stepwise?\n(Enter 0 for NO\t press any other key for YES)\n");
scanf("%d",&c);
a[0]=-1;
for(i=1;i<n;i++)
{
for(j=1;j<i;j++)
{
if(a[i]<a[j])
{
t=a[j];
a[j]=a[i];
m=i;
while(m>j+1)
{
a[m]=a[m-1];
m--;
}
a[j+1]=t;
}}
if(c!=0)
{
printf("\nPASS %d:",i);
for(int x=0;x<n;x++)
printf("%4d",a[x]);
}
}
printf("\nSorted array:\n");
for(i=1;i<n;i++)
printf("%4d",a[i]);
getch();
}
