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
node* create(int x=0)
{
node *temp;
temp=(node*)malloc(sizeof(node));
temp->info=x;
return temp;
}
void push(int);
void enter(int);
void display();
int search(int);
void main()
{
int i,n,x,c;
clrscr();
start=create();
printf("\n Enter the number of nodes ");
scanf("%d",&n);
enter(n);
printf("\nEnter the number to be searched ");
scanf("%d",&x);
c=search(x);
display();
if(c==0)
printf("\n%d not found!",x);
else
printf("\n%d is present in the list!",x);
getch();
}
int search(int x)
{
node *ptr;
ptr=start;
while(ptr->link!='\0')
{
if(ptr->info==x)
return 1;
ptr=ptr->link;
}
return 0;
}
void display()
{
printf("\nEntered list is as follows:\n");
node *ptr;
ptr=start;
while(1)
{
printf("%d\t",ptr->info);
if(ptr->link=='\0') break;
ptr=ptr->link;
}
}
void push(int x)
{
node *temp;
temp=create(x);
temp->link=start;
start=temp;
}
void enter(int n)
{
node *ptr;
int x;
ptr=start;
printf("\nEnter data in list :");
for(int i=1;i<=n;i++)
{
printf("\nNode %d : ",i);
scanf("%d",&x);
ptr->info=x;
if(i==n)
ptr->link='\0';
else
{
ptr->link=(node*)malloc(sizeof(node));
ptr=ptr->link;
}
}
}