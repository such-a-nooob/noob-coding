#include<stdio.h>
#include<math.h>
#include<conio.h>
float *r1;float*r2;
int root(float,float,float);
void main()
{
float a,b,c;
int x;
printf("\nEnter the values of a, b and c : ");
scanf("%f%f%f",&a,&b,&c);
root(a,b,c);
if(x)
printf("\nRoots :\n1)\t%f\n2)\t%f",*r1,*r2);
else
printf("\nNo real roots ");
getch();
}
int root(float a,float b,float c)
{
int x;
x=(b*b)-(4*a*c);
if(x<0.0)
{
return 0;
}
else
{
*r1=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
*r2=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
return 1;
}
}