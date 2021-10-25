#include<stdio.h>
#include<conio.h>
int sum(int n);
void main()
{
int n,s;
clrscr();
printf("Enter a number ");
scanf("%d",&n);
s=sum(n);
printf("\nSum = %d",s);
getch();
}
int sum(int n)
{
int s=0;
if(n!=0)
{
s+=n+sum(n-1);
return (s);
}
else return 0;
}