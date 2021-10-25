#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
cout<<"Enter a number ";
cin>>n;
m=n;
while(n)
{
d=n%10;
s+=(d*d*d);
n/=10;
}
if(s==m)
cout<<"\nEntered number is armstrong number ";
else
cout<<"\nEntered number is not an armstrong number ";
getch();
}

