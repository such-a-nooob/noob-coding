#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
char s[1000],w[50];
int f=0,i,j,l1,m,c,l2,wl,sl;
clrscr();
printf("\nWrite a paragraph\n");
gets(s);
/*
i=0;
while((m=getchar())!=EOF)
//to enter a paragraph. Result will be shown when Ctrl+f5 will be pressed.
s[i++]=m;
s[i]='\0';
*/
printf("\nEnter a word to be searched in the paragraph \n");
getch(w);
sl=strlen(s);
l1=-1;
for(i=0;i<=sl;i++)
{
if(s[i]==' '||s[i]=='\0')
{
l2=i;
wl=l2-l1-1;
for(j=l1+1,c=0;j<l2;j++,c++)
if(s[j]==w[c])
f++;
l1=l2;
}
if(f==wl)
break;
}
if(f==wl)
printf("\n%s is present in the paragraph.",w);
else
printf("\nWord not found ");
getch();
}
