#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class teacher
{
char name[20],sub[10];
float basic,hra,da,salary;
float cal()
{
salary=hra+da+basic;
return salary;
}
public:
void read()
{
cout<<"Enter name, subject, hra, da, and basic \n";
gets(name);
gets(sub);
cin>>hra>>da>>basic;
salary=cal();
}
void display()
{
cout<<"\n\nname "<<name<<"\nsubject "<<sub<<"\nsalary "<<salary;
}
};
void main()
{
clrscr();
teacher t;
t.read();
t.display();
getch();
}