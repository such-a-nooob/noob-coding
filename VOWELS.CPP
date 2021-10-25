#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char s[1000];int v=0,i;
printf("\nEnter a paragraph \n");
gets(s);
for(i=0;s[i]!='\0';i++)
{
if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
v++;
}
printf("number of vowels = %d ",v);
getch();
}
