#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char s[20];
int i,j,l;
clrscr();
printf("\nEnter a word ");
gets(s);
l=strlen(s);
l--;
for(i=l,j=0;i>0;i--,j++)
{
if(s[i]!=s[j])
break;
}
if(j==l)
printf("\npalindrome! ");
else
printf("\nnot palindrome!");
getch();
}