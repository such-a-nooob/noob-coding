#include<conio.h>
#include<ctype.h>
#include<stdio.h>
void ccomment(char);
void complex();
void single();
void quote();
FILE *f1,*f2;
char c;
void main()
{
clrscr();
f1=fopen("C://TURBOC3//BIN//COMMENT_.cpp","r");
f2=fopen("newfile.txt","w");
while((c=fgetc(f1))!=EOF)
ccomment(c);
fclose(f1);
fclose(f2);
getch();
}
void ccomment(char c)
{
char d;
if(c=='/')
{
if((d=fgetc(f1))=='*') complex();
else if(d=='/') single();
else
{
putchar(c);
putchar(d);
fputc(c,f2);
fputc(d,f2);
}
}
else if(c=='\"'||c=='\'') quote();
else
{
putchar(c);
fputc(c,f2);
}
}
void complex()
{
char a;
c=fgetc(f1);
while((c=fgetc(f1))!=EOF)
{
if(a=='*'&& c=='/')
return;
else
a=c;
}
/*
while(c!='*'&&a!='/')
{
a=c;
c=fgetc(f1);
}
*/
}
void single()
{
while((c=fgetc(f1))!='\n'&& c!=EOF);
fputc('\n',f2);
}
void quote()
{
int d,a;
d=c;
fputc(c,f2);
putchar(c);
while((c=fgetc(f1))!=d)
{
fputc(c,f2);
putchar(c);
if(c=='\\')
{
a=getc(f1);
fputc(a,f2);
}
}
fputc(c,f2);
putchar(c);
}


