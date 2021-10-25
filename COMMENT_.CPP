/*copied from internet
using AMU intranet
heheh*/
#include<conio.h>
#include<stdio.h>
#include<string.h>
/* FUNCTION DECLARATION (PROTOTYPE)
declared globally */
void rcom(int);  //read comment
void incom();
void eq(int); //echo quote - DON'T KNOW WHAT FUNCTION IT PERFORMS!
FILE *f1; /*pointer to store the location of the file
on which the operations will be performed*/
void main()
{
printf("\nHey there! \nHere's the program without comment lines\n");
int c,d;
clrscr();
//opening a file in read only format
f1=fopen("C://TURBOC3//BIN//link_lis.cpp","r");
while((c=getc(f1))!=EOF)
rcom(c);
fclose(f1);//closing the file
getch();
}
void rcom(int c)
{
int d;
if(c=='/')
{
if((d=getc(f1))!='*')   //multiple line comment
incom();
else if(d=='/') //single line comment
{
putchar(c);
rcom(d); //reccursion - DUN KNOW WHY IT IS USED
}
else
{
putchar(c);
putchar(d);
}
}
/* perhaps to check for quotes */
else if(c=='\''||c=='"')
eq(c);
else
putchar(c);
}
void incom() //sailing inside the comments........
{
int c,d;
c=getc(f1);
d=getc(f1);
while(c!='*'||d!='/')
{
c=d;
d=getc(f1);
}
}
/*NO IDEA ABOUT WHATS HAPPENNING NEXT */
void eq(int c)
{
int d;
putchar(c);
while((d=getc(f1))!=c)
{
putchar(d);
if(d=='\\')
putchar((getc(f1)));
}
putchar(d);
}
//GOOD BYE!
//TAKE CARE!
