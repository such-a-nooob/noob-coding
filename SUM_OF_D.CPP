#include<iostream.h>
#include<conio.h>
void main()
{
int i,j,m,n,s1=0,s2=0,a[20][20];
clrscr();
cout<<"\nEnter the number of rows and coloumns of the 2D array ";
cin>>m>>n;
if(m==n)
{
cout<<"\nEnter "<<m*n<<" elements in "<<m<<" X "<<n<<" matrix  ";
for(i=0;i<m;i++)
{
for(j=0;j<m;j++)
cin>>a[i][j];
}
cout<<"\nEntered 2D  matrix is :\n";
for(i=0;i<m;i++)
{
for(j=0;j<m;j++)
cout<<a[i][j]<<'\t';
cout<<endl;
}
for(i=0;i<m;i++)
{
for(j=0;j<m;j++)
{
if(i==j)
s1+=a[i][j];
if(i+j==n-1)
s2+=a[i][j];
}
}
cout<<"\nSum of left diagonal is "<<s1<<"\nSum of right diagonal is "<<s2;
}
else
cout<<"\n Matrix is not square matrix.\nCan't find the sum of diagonals. ";
getch();
}