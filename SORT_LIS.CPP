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
node* create_node(int x)
{
node *temp;
temp=(node*)malloc(sizeof(node));
temp->info=x;
return temp;
}
void append(int,node*);
void push(int);
void enter();
void print();
void insert(int);
void main()
{
int x;
clrscr();
printf("\nEnter the value of starting pointer\t");
scanf("%d",&start);
enter();
printf("\nEnter a node to be inserted\t");
scanf("%d",&x);
insert(x);
printf("\n**********************************************\n        SORTED LIST AFTER INSERTION       \n\n");
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
void append(int x,node *ptr)
{
node *temp;
temp=create_node(x);
ptr->link=temp;
temp->link='\0';
}
void insert(int x)
{
node *temp,*ptr1,*ptr2;
ptr1=start;
ptr2=ptr1->link;
temp=create_node(x);
if((ptr1=='\0')||(ptr1->info > temp->info))
{
push(x);
return;
}
while(ptr1->link!='\0')
{
if((ptr1->info < temp->info)&&(ptr2->info > temp->info))
{
temp->link=ptr1->link;
ptr1->link=temp;
return;
}
ptr1=ptr1->link;
ptr2=ptr2->link;
}
if(ptr1->info < temp->info)
{
append(x,ptr1);
return;
}
}
void print()
{
node *ptr;
ptr=start;
while(1)
{
printf("%d\t",ptr->info);
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
if(n!=0)
{
printf("\nEnter data in nodes (ascending order)\n");
for(i=1;i<=n;i++)
{
printf("\n Node %d\t",i);
scanf("%d",&x);
ptr->info=x;
if(i==n)
ptr->link='\0';
else
{
ptr->link=(node*)malloc(sizeof(node));
ptr=ptr->link;
}}
}}

