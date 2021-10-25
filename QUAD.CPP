#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int a,b,c; float x1,x2;
cout<<"Compairing yor quadratic equation to ax^2+bx+c , enter the values \n";
cout<<"a = "; cin>>a;
cout<<"\nb = "; cin>>b;
cout<<"\nc = "; cin>>c;
x1= (-b+sqrt((b*b)-(4*a*c)))/(2*a);
x2= (-b-sqrt((b*b)-(4*a*c)))/(2*a);
cout<<"\n The value of x is found to be\a\t "<<x1<<" and "<<x2;
getch();
}
