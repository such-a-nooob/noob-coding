#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct
{
char name[40],eno[10];
float marks[3];
}smarks;
smarks m[50];
float avg[50];
void getData(int);
void arrange(int);
void display(int);
void sessional(int);
void main()
{
int n;
clrscr();
printf("\nEnter the number of students\t");
scanf("%d",&n);
printf("\nEnter details of %d students",n);
getData(n);
sessional(n);
display(n);
getch();
}
void getData(int n)
{
for(int i=0;i<n;i++)
{
printf("\nStudent %d:",i+1);
printf("\nName\t"); scanf("%s",m[i].name);
printf("Enrol.no.\t"); scanf("%s",m[i].eno);
for(int j=0;j<3;j++)
{
printf("Marks in Sessional %d\t",j+1);
scanf("%f",&m[i].marks[j]);
}
}
}
void sessional(int n)
{
float l1,l2;
int i;
for(i=0;i<n;i++)
{
if(m[i].marks[0]<m[i].marks[1] && m[i].marks[0]<m[i].marks[2])
{
l1=m[i].marks[1];
l2=m[i].marks[2];
}
else if(m[i].marks[1]<m[i].marks[0] && m[i].marks[1]<m[i].marks[2])
{
l1=m[i].marks[0];
l2=m[i].marks[2];
}
else
{
l1=m[i].marks[1];
l2=m[i].marks[0];
}
avg[i]=(l1+l2)/2;
}
}
void display(int n)
{
clrscr();
int a; a=n;
arrange(a);
printf("\nStudent\t\tName\t\tEnroll.no.\t\tSessional Marks\n");
for(int i=0;i<n;i++)
{
printf("\n");
printf("%d\t\t",i+1);
printf("%s\t\t",m[i].name);
printf("%s\t\t\t",m[i].eno);
printf("%f",avg[i]);
}
}
void arrange(int n)
{
char t[20];
float c;
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(strcmpi(m[i].name,m[j].name)>0)
{
strcpy(t,m[i].name);
strcpy(m[i].name,m[j].name);
strcpy(m[j].name,t);
c=avg[i];
avg[i]=avg[j];
avg[j]=c;
strcpy(t,m[i].eno);
strcpy(m[i].eno,m[j].eno);
strcpy(m[j].eno,t);
}
}
}
}