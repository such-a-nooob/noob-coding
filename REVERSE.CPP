#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n,d,r=0;
cout<<"\nEnter a number ";
cin>>n;
while(n)
{
d=n%10;
r=r*10+d;
n/=10;
}
cout<<"\nReverse is "<<r;
getch();
}
