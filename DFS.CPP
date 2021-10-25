//IMPLEMENTATION OF
// dfs algo implement
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define SIZE 50

int big;

struct node
{
    int vertex;
    struct node* next;
};

typedef struct node node;
node* createNode(int v);

struct stack
{
int value[SIZE];
int top;
};
typedef struct stack stack;
stack* createStack();
void push(stack*,int);
int pop(stack*);
int isEmpty(stack*);
void printStack(stack*);

struct AdjList
{
node* head;
};

typedef struct AdjList AdjList;

struct Tree
{
    int numVertices;
    int* visited;
    AdjList* array;
};

typedef struct Tree Tree;
Tree* createTree(int);
void addEdge(Tree*, int, int);
void printTree(Tree*);
int DFS(Tree*, int, int);
void traversal(Tree*, int);
void main()
{
    int again;
    do
    {
	clrscr();
	int numVertices,parent,child,root,num,present=0,cont;
	printf("CREATE A TREE");
	printf("\n*************************************************************************\n");
	printf("Enter the number of vertices in the tree: \t");
	scanf("%d",&numVertices);
	printf("Enter the root of the tree:\t");
	scanf("%d",&root);
	big=root;
	Tree* tree = createTree(numVertices+1);

	for(int i=1;i<=numVertices-1;i++)
	{
		printf("\nAdd Edge %d from parent to child\nParent:\t",i);
		scanf("%d",&parent);
		printf("Child:\t");
		scanf("%d",&child);
		addEdge(tree,parent,child);
		if(big<parent)
			big=parent;
		if(big<child)
			big=child;
	}

	do
	{
		clrscr();
		printTree(tree);
		printf("\n*************************************************************************\n");
		traversal(tree,root);
		printf("\n*************************************************************************\n");
		printf("\nEnter the number to be searched:\t");
		scanf("%d",&num);
		present=DFS(tree,root,num);
		if(present)
			printf("\nSearch successful!");
		else
			printf("\nNumber not in the tree!");

		getch();
		clrscr();
		printf("\n\n\n\n\nContinue seraching?\t(Press 0 to exit)\n");
		printf("\n*************************************************************************\n");
		scanf("%d",&cont);
	}while(cont!=0);

	clrscr();
	printf("\n\n\n\n\nContinue with a new tree?\t(Press 0 to Exit)\n");
	printf("\n*************************************************************************\n");
	scanf("%d",&again);

   }while(again!=0);

    getch();
}

void traversal(Tree* tree, int vertex)
{

	stack *s = createStack();
	push(s,vertex);

	while(!isEmpty(s))
	{
	    printStack(s);
	    vertex= pop(s);

	    if(tree->visited[vertex] == 0)
	    {
		printf("\nVisited: %d\n",vertex);
		tree->visited[vertex]=1;
	    }

	    for(node* i= tree->array[vertex].head;i!='\0';i=i->next)
	    {
		if(tree->visited[i->vertex]==0)
			push(s,i->vertex);
	    }
	}
}

int DFS(Tree* tree, int vertex, int num)
{
	stack *s = createStack();
	push(s,vertex);

	while(!isEmpty(s))
	{
	    vertex= pop(s);

	    if(tree->visited[vertex] == 0)
	    {
		//printStack(s);
		//printf("\nVisited: %d",vertex);
		tree->visited[vertex]=1;
	    }

	    for(node* i= tree->array[vertex].head;i!='\0';i=i->next)
	    {
		if(tree->visited[i->vertex]==0)
			push(s,i->vertex);
	    }
	}

	for(int x=0;x<=big;x++)
		if(tree->visited[x]==1)
			if(x==num)
				return 1;
	return 0;
}

node* createNode(int v)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Tree* createTree(int vertices)
{
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->numVertices = vertices;

    tree->array = (AdjList*)malloc(vertices*10 * sizeof(AdjList*));

    tree->visited = (int*)malloc(vertices*10 * sizeof(int));

    int i;
    for (i = 0; i < vertices*10; i++)
   {
	tree->array[i].head = '\0';
	tree->visited[i] = 0;
    }
    return tree;
}

void addEdge(Tree* tree, int parent, int child)
{
    node* newNode = createNode(child);
    newNode->next = tree->array[parent].head;
    tree->array[parent].head = newNode;
}

stack* createStack()
{
    stack* s =(stack*)malloc(sizeof(stack));
    s->top = -1;
    for(int i=0;i<SIZE;i++)
	s->value[i]='\0';
    return s;
}

int isEmpty(stack* s)
{
    if(s->top == -1)
	return 1;
    else
	return 0;
}

void push(stack* s, int value)
{
    if(s->top == SIZE-1)
	printf("\nStack is Full!!");
	//s->top=0;
    else
    {
	s->top++;
	s->value[s->top] = value;
    }
}

int pop(stack* s)
{
    int item;
    if(isEmpty(s))
    {
	printf("\nStack is empty");
	//item = -1;
    }
    else
    {
	item = s->value[s->top];
	(s->top)--;
    }
    return item;
}

void printStack(stack *s)
{
    int i = s->top;
    if(isEmpty(s))
	printf("\nStack contains :\t\\0");
    else
    {
	printf("\nStack contains :\t");
	for(i = 0; i < s->top + 1; i++)
		printf("\t %d", s->value[i]);
    }
}

void printTree(Tree* tree)
{
    int v;
    for (v = 0; v < big; v++)
    {
	node* temp = tree->array[v].head;
	if(!temp)	continue;
	printf("\n %d -> ", v);

	while (temp)
	{
	    printf("%d -> ", temp->vertex);
	    temp = temp->next;
	}
	printf("\\0\n");
    }
}
