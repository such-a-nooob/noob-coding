#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int n; float i,x,s=0;
cout<<"Enter the number of terms ";
cin>>n;
cout<<"\nEnter a number ";
cin>>x;
for(i=1;i<=n;i++)
{
cout<<pow((-1),i)*(pow(x,i))<<'\t';
s+=pow((-1),i)*(pow(x,i));
}
cout<<"\nSum of given series: "<<s;
getch();
}
