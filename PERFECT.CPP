#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n,s=0;
cout<<"Enter a number ";
cin>>n;
for(int i=1;i<=n;i++)
{
if(n%i==0)
s+=i;
}
if(s==n)
cout<<"\nEntered number is a perfect number ";
else
cout<<"\nEntered number is not a perfect number ";
getch();
}
