#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n,m,d,r=0;
cout<<"Enter a number to be checked ";
cin>>m;
n=m;
while(m!=0)
{
d=m%10;
r=(r*10)+d;
m/=10;
}
if(r==n)
cout<<"\n Entered number is a palindrome ";
else
cout<<"\n Entered number is not a palindrome ";
getch();
}
