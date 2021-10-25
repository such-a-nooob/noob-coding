// arrange a list of students alphabetically using strcmpi
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
for(j=i+1;j<n;j++)
if(strcmpi(a[i],a[j])>0)
{
strcpy(c,a[i]);
strcpy(a[i],a[j]);
strcpy(a[j],c);
}
printf("\nNames sorted in alphabetical order\n");
for(i=0;i<n;i++)
printf("%d\t%s\n",i+1,a[i]);
getch();
}

