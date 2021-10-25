#include<iostream.h>
#include<math.h>
#include<conio.h>
void main()
{
clrscr();
int i,n,x;
cout<<"Enter the number of terms ";
cin>>n;
cout<<"\nEnter the number ";
cin>>x;
for(i=1;i<=n;i++)
cout<<pow(x,i)<<'\t';
getch();
}

