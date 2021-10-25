/*insertion sort*/
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
int a[50],i,j,n,t,c;
clrscr();
printf("\n Enter the number of terms in array ");
scanf("%d",&n);
printf("\n Enter %d terms in array\n",n);
for(i=1;i<=n;i++) scanf("%d",&a[i]);
printf("\nWant to see Stepwise?\n(Enter 0 for NO\t press any other key for YES)\n");
scanf("%d",&c);
a[0]=-1;
for(i=1;i<=n;i++)
{
if(a[i]<a[i-1])
{
j=i-1;
t=a[i];
while(t<a[j])
{
a[j+1]=a[j];
j--;
}
a[j+1]=t;
if(c!=0)
{
for(int x=1;x<=n;x++)
printf("%d\t",a[x]);
printf("\n");
}
}
}
printf("\nSorted array :\n");
for(i=1;i<=n;i++)
printf("%d\t",a[i]);
getch();
}