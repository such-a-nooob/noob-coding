#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int i,n,x=1;
cout<<"Enter the number of terms in the series ";
cin>>n;
cout<<"\nThe series is as follows:\n\n";
for(i=0;i<n;i++)
{
cout<<pow(-1,i)*x<<"\t\t";
x+=3;
}
getch();
}
