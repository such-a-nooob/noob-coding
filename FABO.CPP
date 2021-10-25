#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a=-1,b=1,n;
long int c=0;
cout<<"Enter the number of terms ";
cin>>n;
cout<<"\n FABONACCI SERIES TILL TERM "<<n<<" IS\n";
while(c<=n)
{
c=0;
c=a+b;
a=b;
b=c;
cout<<c<<'\t';
}
getch();
}

