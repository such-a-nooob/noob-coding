#include<iostream.h>
#include<conio.h>
#include<string.h>
void main()
{
int f=0,n;
do
{
clrscr();
cout<<"\nEnter number (0 to exit):\t";
cin>>n;
f++;
}while(n!=0);
cout<<"\nNumbers Entered: "<<f;
getch();
}