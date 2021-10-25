#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
char a[30];
int l,i,j,f=0;
printf("\nEnter a word ");
gets(a);
for(l=0;a[l]!='\0';l++);
l--;
for(i=0,j=l;i<(l/2);i++,j--)
{
if(a[i]!=a[j])
f++;
}
if(f==0)
printf("\n Word is palindrome ");
else
printf("\n Word is not a palindrome ");
getch();
}


























































