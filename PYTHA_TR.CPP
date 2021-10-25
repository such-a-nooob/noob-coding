// possible values (under 100) of a right triangle
#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
int a,b,c,i,j,k,f=0;
for(i=100;i>1;i--)
{
a=0;b=0;c=0,f=0;
for(j=100-1;j>1;j--)
{
for(k=100-2;k>1;k--)
{
if(pow(i,2)==pow(j,2)+pow(k,2))
{
f++;
a=i;b=j;c=k;
}
}
}
if(f)
cout<<c<<'\t'<<b<<'\t'<<a<<'\n';
}
getch();
}