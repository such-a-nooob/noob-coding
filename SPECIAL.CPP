#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n,m,f=1,d,s=0;
cout<<"Enter a number ";
cin>>n;
m=n;
while(n)
{
d=n%10;
for(int i=1;i<=d;i++)
f*=i;
s+=f;
n/=10;
f=1;
}
if(s==m)
cout<<"\nEntered number is a special number ";
else
cout<<"\nEntered number is not a special number ";
getch();
}


