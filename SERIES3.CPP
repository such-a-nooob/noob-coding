//LUC'S SERIES
#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int i,n,a,b,c,t;
cout<<"Enter the first three terms of series ";
cin>>a>>b>>c;
cout<<"Enter the number of terms in the series ";
cin>>n;
cout<<"\nThe series is as follows:\n\n";
cout<<a<<'\t'<<b<<'\t'<<c<<'\t';
for(i=1;i<=n;i++)
{
cout<<a+b+c<<'\t';
t=a+b+c;
a=b;
b=c;
c=t;
}
getch();
}