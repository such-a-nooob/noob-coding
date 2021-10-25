#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int x,n,s=0;
cout<<"Enter a number ";
cin>>x;
cout<<"\nEnter the value of n ";
cin>>n;
cout<<"\n Here's a series in the form of 1,x,x^2,x^3......x^n\n";
for(int i=0;i<=n;i++)
{
cout<<pow(x,i)<<'\t';
s+=pow(x,i);
}
cout<<"\n\nSum of the above series is "<<s;
getch();
}

