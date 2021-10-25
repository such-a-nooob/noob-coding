// implementation of
// BREDTH FIRST SEARCH algorithm
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<process.h>
#define SIZE 50

int big;

struct queue
{
    int items[SIZE],front,rear;
};

typedef struct queue queue;
queue* createQueue();
void enqueue(queue* , int);
int dequeue(queue* );
int isEmpty(queue* );
void printQueue(queue*);

struct node
{
    int vertex;
    struct node* next;
};

typedef struct node node;
node* createNode(int);

struct AdjList
{
node* head;
};

typedef struct AdjList AdjList;

struct Tree
{
    int numVertices;
    AdjList* array;
};

typedef struct Tree Tree;
Tree* createTree(int);
void addEdge(Tree*, int, int);
void printTree(Tree*);
void traversal(Tree*,int);
int BFS(Tree*, int, int);

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
	big = root;
	Tree* tree = createTree(numVertices+1);
	for(int i=1;i<=numVertices-1;i++)
	 {
		printf("\nAdd Edge %d from parent to child\nParent:\t",i);
		scanf("%d",&parent);
		printf("Child:\t");
		scanf("%d",&child);
		if(big<parent) big=parent;
		if(big<child) big=child;
		addEdge(tree,parent,child);
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
		present=BFS(tree, root,num);
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

void traversal(Tree* tree, int root)
{
    queue* q = createQueue();
    enqueue(q, root);

    while(!isEmpty(q))
    {
	printQueue(q);
	int currentVertex = dequeue(q);
	printf("\nVisited :%d",currentVertex);

	node* temp = tree->array[currentVertex].head;

	while(temp)
	{
	    int children = temp->vertex;
	    enqueue(q, children);
	    temp = temp->next;
	}

    }
}

int BFS(Tree* tree, int root,int num)
{
    queue* q = createQueue();
    enqueue(q, root);

    while(!isEmpty(q))
    {
	int currentVertex = dequeue(q);
	if(currentVertex==num)	return 1;

	node* temp = tree->array[currentVertex].head;

	while(temp)
	{
	    int children = temp->vertex;
	    enqueue(q, children);
	    temp = temp->next;
	}

    }
    return 0;
}

node* createNode(int v)
{
    node* newNode =(node*)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Tree* createTree(int vertices)
{
    Tree* tree =(Tree*) malloc(sizeof(Tree));
    tree->numVertices = vertices;
    tree->array =(AdjList*) malloc(vertices * 10 * sizeof(AdjList));

    for (int i=0; i<vertices*10; i++)
	tree->array[i].head = NULL;

    return tree;
}

void addEdge(Tree* tree, int parent, int child)
{
    // Add edge from parent to child
    node* newNode = createNode(child);
    newNode->next = tree->array[parent].head;
    tree->array[parent].head = newNode;
}

queue* createQueue()
{
    queue* q =(queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    for(int i=0;i<SIZE;i++)
	q->items[i]='\0';
    return q;
}

int isEmpty(queue* q) 
{
    if(q->rear == -1)
	return 1;
    else
	return 0;
}

void enqueue(queue* q, int value)
{
    if(q->rear == SIZE-1)
	//printf("\nQueue is Full!!");
	q->rear=0;
    else 
    {
	if(q->front == -1)
	    q->front = 0;
	q->rear++;
	q->items[q->rear] = value;
    }
}

int dequeue(queue* q)
{
    int item;
    if(isEmpty(q))
    {
	//printf("\nQueue is empty");
	item = -1;
    }
    else
    {
	item = q->items[q->front];
	(q->front)++;
	if(q->front > q->rear)
	{
	    //printf("\nResetting queue");
	    q->front = q->rear = -1;
    	}
    }
    return item;
}

void printQueue(queue *q)
{
    int i = q->front;
    if(isEmpty(q)) 
	printf("\nQueue contains :\t\\0");
    else 
    {
	printf("\nQueue contains :\t");
	for(i = q->front; i < q->rear + 1; i++) 
		printf("%d ", q->items[i]);
    }
}

void printTree(Tree* tree)
{
    int v;
    printf("\nAdjacency lists of the tree :");
    for (v = 0; v <= big; v++)
    {
	node* temp = tree->array[v].head;
	if(!temp) continue;
	printf("\n%d ->", v);
	while (temp)
	{
	    printf("%d -> ", temp->vertex);
	    temp = temp->next;
	}
	printf("\\0\n");
    }
}