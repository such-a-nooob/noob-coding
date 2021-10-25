#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int i,c,j;
char str[50];
printf("Enter a string ");
gets(str);
for(i=0,j=strlen(str)-1;i<j;i++,j--)
{
c=str[i];
str[i]=str[j];
str[j]=c;
}
puts(str);
getch();
}