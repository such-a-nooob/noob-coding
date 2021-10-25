#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n;float s=0;
cout<<"Enter the number of terms : ";
cin>>n;
for(float i=1;i<n*2;i+=2)
{
cout<<(i+1)<<'/'<<i<<'\t';
s+=(i+1)/i;
}
cout<<"\nSum of the following series is : "<<s;
getch();
}
