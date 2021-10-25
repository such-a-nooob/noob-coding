#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>

struct node
{
int value;
//char value;
struct node* left;
struct node* right;
};
typedef struct node node;

node* createNode(int x)
{
node* temp = (node*)malloc(sizeof(node));
temp->value=x;
temp->left='\0';
temp->right='\0';
return temp;
}

node* insertNode(node* temp,int val)
{
node *newNode=createNode(val);
if(!temp)
{
//printf("%d inserted!\n",val);
return newNode;
}
if(temp->value <= val)
{
insertNode(temp->right, val);
if(!(temp->right))
temp->right=newNode;
}
if(temp->value > val)
{
insertNode(temp->left , val);
if(!(temp->left))
temp->left=newNode;
}
return temp;
}


/*
node* insertNode(node* temp,int val)
{
node *newNode=createNode(val);
if(!temp)
{
printf("%d inserted!\n",val);
return newNode;
}
if(temp->value <= val)
{
insertNode(temp->right, val);
if(!(temp->right))
temp->right=newNode;
}
if(temp->value > val)
{
insertNode(temp->left , val);
if(!(temp->left))
temp->left=newNode;
}
return temp;
}

node* createBST(int a[],int l)
{
int i=0;
node *root='\0';
while(i<l)
{
printf("%d\n",a[i]);
root=insertNode(root,a[i]);
i++;
}
return root;
}
*/

node* createBST()
{
int val,num,n;
node *root='\0';
FILE* fp1=fopen("treeNodes.txt","r");
if(!fp1)
printf("Cant access file!");
while((val=fgetc(fp1))!=EOF)
{
if(val==' ')  continue;
val=(int)val-48;
if(val<0) continue;
n=num=val;
if((val=fgetc(fp1))!=' ')
{
val=(int)val-48;
num=(num*10)+val;
if(num<0)
{
root=insertNode(root,n);
continue;
}
}
root=insertNode(root,num);
}
fclose(fp1);
return root;
}

void printTree1(node* temp)
{
//in-order print of tree temp
if (temp != NULL)
{
printTree1(temp->left);
printf("%d\t", temp->value);
printTree1(temp->right);
}
}

void printTree2(node* temp)
{
//pre-order print of tree temp
if (temp != NULL)
{
printf("%d\t", temp->value);
printTree2(temp->left);
printTree2(temp->right);
}
}

void printTree3(node* temp)
{
//post-order print of tree temp
if (temp != NULL)
{
printTree3(temp->left);
printTree3(temp->right);
printf("%d\t", temp->value);
}
}


void main(void)
{
clrscr();
//perror("fopen");
node *tree;
tree=createBST();
//printf("\n");
printf("\nin-order traversal\n");
printTree1(tree);
//printf("\n");
printf("\npre-order traversal\n");
printTree2(tree);
//printf("\n");
printf("\npost-order traversal\n");
printTree3(tree);
getch();
}

/*
void main (void)
{
clrscr();
node *tree;
int a[]={8,4,10,9,11},l=5;
tree=createBST(a,l);
printf("\n");
printTree1(tree);
printf("\n");
printTree2(tree);
printf("\n");
printTree3(tree);
getch();
}
*/