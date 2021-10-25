#include<stdio.h>
#include<conio.h>
#define n 10
void main()
{
int front=0,rear=0,q[n],i,c,ch=1,j=0;
clrscr();
while(ch!=0)
{
clrscr();
printf("\n1.Insert\n2.Delete\n3.Display\nEnter your choice\t");
scanf("%d",&c);
switch(c)
{
case 1:
if(front==0 && rear==n)
{
printf("\nQueue is full-overflow condition");
break;
}
printf("\nEnter number %d in queue",++j);
scanf("%d",&q[rear++]);
if(front==0 && rear==0) front++;
break;
case 2:
if(front==rear)
printf("\nQueue is empty-underflow condition");
else
{
printf("\nDeleted item is %d ",q[front]);
q[front++]='\0';
}
break;
case 3:
if(rear==front)
printf("\nQueue is empty");
else
{
printf("\nQueue:\n");
for(i=front;i<rear;i++)
printf("%d\t",q[i]);
}
break;
default:printf("\nInvalid Choice");
}
printf("\nWanna Continue?(0/1) ");
scanf("%d",&ch);
}
getch();
}