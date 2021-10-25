#include<stdio.h>
#include<conio.h>
void main()
{
int l,a,b,c;
printf("\nEnter 3 numbers ");
scanf("%d%d%d",&a,&b,&c);
l=(a>b)?((a>c)?a:c):((b>c)?b:c);
printf("\nLargest number : %d ",l);
getch();
}