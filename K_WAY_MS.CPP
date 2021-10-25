#include<conio.h>
#include<stdio.h>
#include<math.h>
void merge_sort(int[],int,int,int);
void main()
{
int a[50],n,i,j,t,s=0;
clrscr();
printf("\nEnter the number of terms in array ");
scanf("%d",&n);
printf("\nEnter %d elements in array \n",n);
for(i=0;i<n;i++)  scanf("%d",&a[i]);
t=2;
while(t<n)
{
for(i=0;i<n;i+=t)
{
for(s=0;;) if(a[s]<a[s+1]) s++; else break;
merge_sort(a,i,s,t);
}
t*=2;
}
printf("\nSorted Array\n ");
for(i=0;i<n;i++)
printf("%4d",a[i]);
getch();
}
void merge_sort(int a[],int f,int s,int l)
{
printf("\nf=%d\ns=%d\nl=%d\n",f,s,l);
int b[50],i,j,k,x,y;
i=f;
j=s;
k=0;
while(i<s && j<l)
{
if(a[i]<a[j])
{ b[k]=a[i]; i++;}
else
{ b[k]=a[j]; j++;}
k++;
}
if(i<s-1)
for(x=k;i<s;x++,i++)  b[x]=a[i];
else
for(x=k;j<l;x++,j++)  b[x]=a[j];
for(y=0,x=f;x<l;x++,y++)  a[x]=b[y];
}















