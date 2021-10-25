#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
float i,x,s=0;
int n;
cout<<"Enter the number of terms ";
cin>>n;
cout<<"\nEnter a number ";
cin>>x;
for(i=1;i<=n;i++)
{
cout<<pow(x,i)<<'/'<<i<<'\t';
s+=pow(x,i)/i;
}
cout<<"\nSum of the following series "<<s;
getch();
}
