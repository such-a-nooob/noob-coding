#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int i,n,x; float s=0;
cout<<"Enter the number of terms in the series ";
cin>>n;
cout<<"\nEnter the value of x ";
cin>>x;
cout<<"\nThe series is as follows:\n\n\a";
for(i=1;i<=n;i++)
{
cout<<(pow(-1,i)*pow(x,i))<<"\t\t";
s+=(pow(-1,i)*pow(x,i));
}
cout<<"\n\n sum of the above series is : "<<s;
getch();
}


