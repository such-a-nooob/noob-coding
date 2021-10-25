#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int f=1,n;
cout<<"Enter a number whose factorial has to be found ";
cin>>n;
for(int i=1;i<=n;i++)
f*=i;
cout<<"\nFactorial of "<<n<<" is "<<f;
getch();
}
