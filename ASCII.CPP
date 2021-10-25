// to find ASCII codes
#include<stdio.h>
#include<conio.h>
void main()
{
int i;
clrscr();
for(i=0;i<=130;i++)
printf("\t%d = %c",i,(char)i);
getch();
}