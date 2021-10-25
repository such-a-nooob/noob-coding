#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n,f=0;
cout<<"Enter a number ";
cin>>n;
for(int i=1;i<=n*n;i++)
if((n*n)%i==0)
f++;
if(f==2)
cout<<"\nThe square of given number is prime ";
else
cout<<"\nThe square of the given number is not prime ";
getch();
}


