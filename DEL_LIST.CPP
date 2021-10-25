/*deletion in linked lists*/
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
void deletenode(int);
void print();
void enter();
void main()
{
int x;
clrscr();
start=create_node();
enter();
printf("\nEnter the number to be deleted\t");
scanf("%d",&x);
deletenode(x);
printf("\nFinal List:\n");
print();
getch();
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
void deletenode(int a)
{
node *ptr,*prev;
prev= start;
ptr=start->link;
while(ptr!='\0')
{
if(ptr->info==a)
{
prev->link=ptr->link;
free(ptr);
}
else if(prev->info==a)
{
start=prev->link;
free(prev);
}
else
{
prev=ptr;
ptr=ptr->link;
}
}
}