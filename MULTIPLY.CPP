#include<stdio.h>
#include<conio.h>
void main()
{
int a[30][30],b[30][30],c[30][30],m,n,p,q,i,j,k;
clrscr();
printf("\nEnter the no. of rows and coloumns of Matrix 1 ");
scanf("%d%d",&m,&n);
printf("\nEnter the no. of rows and coloumns of Matrix 2 ");
scanf("%d%d",&p,&q);
if(n!=p)
printf("\nCan't multiply the above matrix\n");
else
{
printf("\nEnter %d elements in Matrix 1\n",m*n);
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
printf("\nEnter %d elements in Matrix 2\n",p*q);
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
scanf("%d",&b[i][j]);
}
clrscr();
printf("\nMatrix 1\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
printf("%d\t",a[i][j]);
printf("\n");
}
printf("\nMatrix 2\n");
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
printf("%d\t",b[i][j]);
printf("\n");
}
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
{
c[i][j]=0;
for(k=0;k<n;k++)
c[i][j]+=a[i][k]*b[k][j];
}}
printf("\nProduct of matrices:\n");
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
printf("%d\t",c[i][j]);
printf("\n");
}
}
getch();
}