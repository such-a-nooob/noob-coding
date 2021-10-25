#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a,n; char c;
do
{
cout<<"\nEnter a number whose table you wanna write ";
cin>>a;
cout<<"\nUpto? ";
cin>>n;
for(int i=1;i<=n;i++)
cout<<'\n'<<a<<" x "<<i<<" = "<<(a*i);
cout<<"\nWanna continue? (Y/N) ";
cin>>c;
}while(c=='y'||c=='Y');
getch();
}

