#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a,b,max,hcf=1,lcm;
cout<<"Enter two numbers ";
cin>>a>>b;
if(a>b)
max=a;
else
max=b;
for(int i=1;i<=max;i++)
{
if(a%i==0 && b%i==0)
hcf*=i;
}
lcm=a*b/hcf;
cout<<"\n LCM = "<<lcm<<"\n HCF = "<<hcf;
getch();
}

