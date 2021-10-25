#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
char a[50][50],c[50]; int i,j,k,n;
clrscr();
printf("\nEnter the number of students\t");
scanf("%d",&n);
printf("\nEnter the names of students\n");
for(i=0;i<n;i++)
{
printf("%d\t",i+1);
scanf("%s",&a[i]);
}
for(i=0;i<n-1;i++)
{for(k=i+1;k<n;k++)
{
if(a[i][0]==a[k][0])
{
j=1;
while(a[i][j]!='\0'||a[k][j]!='\0')
{
if(a[i][j]>a[k][j])
{
strcpy(c,a[i]);
strcpy(a[i],a[k]);
strcpy(a[k],c);
}
if(a[i][j]==a[k][j]) j++;
else break;
}
}
else
{
if(a[i][0]>a[k][0])
{strcpy(c,a[i]);
strcpy(a[i],a[k]);
strcpy(a[k],c);
}}
}}
printf("\nNames sorted in alphabetical order\n");
for(i=0;i<n;i++)
printf("%d\t%s\n",i+1,a[i]);
getch();
}

