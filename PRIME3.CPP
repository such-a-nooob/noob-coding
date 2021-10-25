#include<stdio.h>
#include<conio.h>
int prime(int ,int);
void main()
{
int a,x;
printf("\nEnter a number ");
scanf("%d",&a);
x=prime(a,a);
if(x>0)
printf(" not prime ");
else
printf(" prime");
getch();
}
int prime(int n,int i)
{
if(i==1)
return 0;
else
{
if(n%i==0)
return 0;
else
return (prime(n,i-1));
}
}
