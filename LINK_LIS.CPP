/*insertion in linked lists*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
typedef struct node node;
node *start;
node* create_node(int x=0)
{
node *temp;
temp=(node *)malloc(sizeof(node));
temp->info=x;
return temp;
}
void push(int);
void insert(int,int);
void append(int);
void print();
void enter();
void main()
{
int x,c,n;
clrscr();
start=create_node();
printf("\nSTART = %d",start);
enter();
printf("\nEnter the number to be inserted\t");
scanf("%d",&x);
printf("\nWhere do you want to insert the number?\n1.At the beginning\n2.At the end\n3.Insert after\nEnter your choice(1/2/3):\t");
scanf("%d",&c);
switch(c)
{
case 1: push(x);
break;
case 2: append(x);
break;
case 3: printf("\nEnter position\t");
scanf("%d",&n);
insert(n,x);
break;
default:printf("\nInvalid choice!");
}
printf("\nFinal List:\n");
print();
getch();
}
void push(int x)
{
node *temp;
temp=create_node(x);
temp->link=start;
start=temp;
}
void append(int x)
{
node *temp,*ptr;
temp=create_node(x);
ptr=start;
while(ptr->link!='\0')
ptr=ptr->link;
ptr->link=temp;
temp->link='\0';
}
void insert(int n,int x)
{
node *temp,*ptr;
ptr=start;
temp=create_node(x);
if(n==1)
{
push(x);
return;
}
for(int i=2;i<=n;i++)
ptr=ptr->link;
if(ptr=='\0')
{
append(x);
return;
}
temp->link=ptr->link;
ptr->link=temp;
}
void print()
{
node *ptr;
ptr=start;
while(1)
{
printf("%d ",ptr->info);
if(ptr->link=='\0') break;
ptr=ptr->link;
}
}
void enter()
{
node *ptr;
ptr=start;
int i,n,x;
printf("\nEnter the number of nodes\t");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter number in node %d\t",i+1);
scanf("%d",&x);
ptr->info=x;
if(i==n-1)
ptr->link='\0';
else if(i<n-1)
{
ptr->link=(node *)malloc(sizeof(node));
ptr=ptr->link;
}
}
}

