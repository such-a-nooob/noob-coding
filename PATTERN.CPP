#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
char s[50];
int i,j,l;
printf("\n Enter a string ");
gets(s);
l=strlen(s);
for(i=0;i<l;i++)
{
for(j=0;j<=i;j++)
printf("%c",s[j]);
printf("\n");
}
for(i=0;i<=l;i++)
printf("%*.*s\n",i,i,s);
getch();
}