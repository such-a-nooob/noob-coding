#include<conio.h>
#include<stdio.h>
int fabo(int);
void main()
{
int n;
clrscr();
printf("Enter a number ");
scanf("%d",&n);
for(int i=1;i<=n;i++)
printf("%d\t",fabo(i));
getch();
}
int fabo(int a)
{
if((a==1)||(a==2))
return 1;
else
return (fabo(a-1)+fabo(a-2));
}

