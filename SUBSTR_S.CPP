#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
char s[1000],w[50];
int f,i,j;
clrscr();
printf("\nWrite a paragraph\n");
gets(s);
printf("\n\nEnter a word to be searched in the paragraph \n");
gets(w);
for(int a=0;s[a]!='\0';a++)
{
if(s[a]==w[0])
{
i=a;
j=0;
while(s[i]==w[j])
{
i++; j++;
}
if(j>=strlen(w))
{
f=1;
break;
}
}
if(f==1) break;
}
if(f==1)
printf("\n%s is present in the paragraph.",w);
else
printf("\nWord not found ");
getch();
}