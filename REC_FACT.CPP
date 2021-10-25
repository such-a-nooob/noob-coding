#include<stdio.h>
#include<conio.h>
int fact(int);
void main()
{
clrscr();
int n;
printf("Enter a number ");
scanf("%d",&n);
printf("\nFactorial = %d",fact(n));
getch();
}
int fact(int a)
{
if(a==1||a==0)
return 1;
else if(a<0)
return 0;
else
return (a*fact(a-1));
}

