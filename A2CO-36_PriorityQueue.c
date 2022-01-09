/*

Implement priority queue in C using the following representations:
1. Unordered Single Array
2. Ordered linked list
3. Multiple array
Each element in the priority queue has an external numeric priority associated with it.

Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define null 0
#define SIZE 100

//maximum size of the queue (given by the user)
int MAX;

// -(i)
// Implementing priority queue using unordered single array

typedef struct 
{
	int a[SIZE], p[SIZE];	
	int front, rear;
}Q;
// A and P are two single arrays for storing elements and their priorities respectively

Q pq; 
Q* singleQ = &pq;

//check if the queue is empty
bool isSAEmpty()
{
	if(singleQ->front == -1 || singleQ->rear == -1)
		return true;
	else
		return false;
}

//check if the queue is full
bool isSAFull()
{
	if((singleQ->front == 0 && singleQ->rear == MAX-1)||(singleQ->front == (singleQ->rear)+1))
			return true;
		else
			return false;
}

//enqueue elements in the unordered single array
void enqueueSA(int x, int y)
{
	if(isSAFull())
	{
		printf("\nQueue is full! Can't insert!\n");
		return;
	}
	//if it's the first element both FRONT and REAR are to be incremented
	if(isSAEmpty())
	{
		(singleQ->front)++;
		(singleQ->rear)++;
	}
	//assuming it to be a circular queue
	else if(singleQ->rear == MAX-1)
		singleQ->rear = 0;
	//cz elements in queue are inserted at the REAR end
	else
		(singleQ->rear)++;

	singleQ->a[singleQ->rear] = x;
	singleQ->p[singleQ->rear] = y;
	printf("\n%d inserted!\nFRONT : %d\tREAR : %d\n",x,singleQ->front, singleQ->rear);
}

//find the index of the element with highest priority
int maxPriority()
{
	int small, max;
	// if REAR < FRONT, the last element with the same priority would be dequeued 
	// cz queue follows FIFO order
	// REAR < FRONT mean that the elements at the beginning of the queue are inserted afterwards but are in the beginning due to the circular property of the queue)
	if((singleQ->rear) < (singleQ->front))
	{
		for(int i=0; i<MAX; i++)
		{
			if((singleQ->p[i] != null) && (singleQ->p[i] <= small))
			{
				small = singleQ->p[i];
				max = i;
			}
		}
	}
	// if it's not the case, the first element with the same priority will be dequeued
	// cz elements in the beginning of the queue were inserted first
	else
	{
		for(int i=0; i<MAX; i++)
		{
			if((singleQ->p[i] != null) && (singleQ->p[i] < small))
			{
				small = singleQ->p[i];
				max = i;
			}
		}
	}
	//returning the index of the element with highest (ascending) priority (i.e. lowest priority number)
	return max;
}

//to fill the gap in the queue, if an element is dequeued from the middle
void shiftRight(int x)
{
	int i;
	for(i=x; i>0; --i)
	{
		singleQ->a[i] = singleQ->a[i-1];
		singleQ->p[i] = singleQ->p[i-1];
	}
	singleQ->a[i] = null;
	singleQ->p[i] = null;
}

//remove the element with the highest priority from the queue
int dequeueSA()
{
	if(isSAEmpty())
	{
		printf("\nQueue is empty!\n");
		return null;
	}
	int x = maxPriority();
	int n = singleQ->a[x];

	//if the element to be deleted is not a middle element (is equal to FRONT), no need to shift the array
	if(singleQ->front != x)
		shiftRight(x);
	else
	{
		singleQ->a[x] = null;
		singleQ->p[x] = null;
	}

	//if the queue contains a single element, set FRONT and REAR to -1 (to mark the queue empty)
	if(singleQ->front == singleQ->rear)
	{
		singleQ->front = -1;
		singleQ->rear = -1;
	}
	//assuming it to be a circular queue
	else if(singleQ->front == MAX-1)
		singleQ->front = 0;
	//cz elements in the queue are deleted from the FRONT end
	else
		(singleQ->front)++;

	//returning the deleted element
	return n;
}

//prints the unordered single array along with the front and rear values
void displaySA()
{
	printf("\n");
	for(int i=0; i<MAX; i++)
		printf("%d (%d) \t", singleQ->a[i], singleQ->p[i]);
	printf("\nFRONT : %d\tREAR : %d\n", singleQ->front, singleQ->rear);					
}

// -(ii)
// Implementing priority queue using an ordered linked list

struct node
{
	int info;
	int p;
	struct node *next;
};
//a single node of the linked list contains - the element, its priority and the address of the next node
typedef struct node node;
node *front = NULL;
node *rear = NULL;

//creating a node and assigning values and memory to it
node* createNode(int x, int y)
{
	node* temp = (node*)malloc(sizeof(node)); 
	temp->info = x;
	temp->p = y;
	temp->next = NULL;
	return temp;
}

//check if list is empty
bool isListEmpty()
{
	if(front == NULL)
		return true;
	else
		return false;
}

//prints the ordered linked list 
void displayLL()
{
	node* temp = front;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d (%d)\t-->\t",temp->info, temp->p);
		temp = temp->next;
	}
	printf("\\0\n");
}

//find the appropiate position (accoring to the priority) to insert a node
int find(int x)
{
	int pos = 0, tpos = 0;	
	
	if(isListEmpty())
	{
		printf("\nQueue is empty!\n");
		return 0;
	}
	
	node* temp = front;

	//if a node of the same priority already exists, insert the new node after the LAST element with same priority
	while(temp!=NULL)
	{
		++pos;
		if(temp->p == x)	tpos = pos;
		temp = temp->next;
	}
	if(tpos)
		return tpos;
	//if no node of such priority exists
	else
	{
		pos = 0; 
		temp = front;
		//if the priority number of new node is smaller than that of existing nodes
		while(temp!=NULL)
		{
			++pos;
			if(temp->p > x) 
			{
				if(pos==1)
					return -1;
				else
					return pos-1;
			}
			temp = temp->next;
		}
	}
	//the priority number of the new node is greater than the that of existing nodes, thus the new node needs to be inserted at the very end of the list
	return pos;
}

//enqueue elements in the linked list orderly (highest priority at the beginning)
void enqueueLL(int x, int y)
{
	node* temp;
	temp = createNode(x, y);

	if(isListEmpty())
	{	
		front = temp;
		rear = temp;
		return;
	}
	
	//find the appropiate position
	int pos = find(y); 
	//if POS = -1, insert in the beginning of the list
	if(pos==-1)
	{
		temp->next = front;
		front = temp;
	}
	//otherwise insert after POS elements
	else
	{
		pos-=1;
		node* ptr = front;
		while(pos!=0)
		{
			ptr = ptr->next;
			pos--;
		} 
		temp->next = ptr->next;
		ptr->next = temp;
		if(temp->next == NULL)
			rear = temp;
	}					
}

//remove the element with the highest priority (first element of the list) from the linked list
int dequeueLL()
{
	int x;
	
	if(isListEmpty())
	{
		printf("\nThe queue is already empty!\n");
		return null;
	}
	
	x = front->info;
	front = front->next;
	return x;
}

// -(iii)
// Implementing priority queue using multiple arrays (2D array)

typedef struct 
{
	int a[SIZE][SIZE];	
	int front[SIZE], rear[SIZE];
}q;
// A is a 2D array, where each row is an independent queue with the priority number equal to its row index
// FRONT and REAR arrays store the values of the front and rear pointers corresponding to each queue 

q PQ; 
q* multiQ = &PQ;

//check if the queue (associated to a particular priority number) is empty
bool isQEmpty(int p)
{
	if(multiQ->front[p] == -1 || multiQ->rear[p] == -1)
		return true;
	else
		return false;
}

//check if the queue (associated to a particular priority number) is full
bool isQFull(int p)
{
	if((multiQ->front[p] == 0 && multiQ->rear[p] == MAX-1)||(multiQ->front[p] == (multiQ->rear[p])+1))
		return true;
	else
		return false;
}

//insert elements in the 2D matrix (where elements have same priority number as the row index)
void enqueueMA(int x, int y)
{
	if(isQFull(y))
	{
		printf("\nQueue is full! Can't insert!\n");
		return;
	}
	if(isQEmpty(y))
	{
		(multiQ->front[y])++;
		(multiQ->rear[y])++;
	}
	else if(multiQ->rear[y] == MAX-1)
		multiQ->rear[y] = 0;
	else
		(multiQ->rear[y])++;

	multiQ->a[y][multiQ->rear[y]] = x;
	
	printf("\n%d inserted!\nFRONT : %d\tREAR : %d\n",x, multiQ->front[y], multiQ->rear[y]);
}

//return the index and priority number of the element with highest priority
void MaxPriority(int *x, int *y)
{
	for(int i=0; i<SIZE; i++)
	{
		//in the first non empty row of the matrix
		if(!isQEmpty(i))
		{
			//return the FRONT (elements in a queue are deleted from the front) and the priority number associated with it
			*x = multiQ->front[i];
			*y = i;
			break;
		}
	}
}

//remove the element with the highest priority from the 2D array
int dequeueMA()
{
	int x = -1, y;
	MaxPriority(&x, &y);
	int n = multiQ->a[y][x];

	//if the 2D array is empty, x will not be changed
	if(x == -1)
	{
		printf("\nCan't dequeue! Queue is empty!\n");
		return null;
	}
	
	multiQ->a[y][x] = null;
	
	if(multiQ->front[y] == multiQ->rear[y])
	{
		multiQ->front[y] = -1;
		multiQ->rear[y] = -1;
	}
	else if(multiQ->front[y] == MAX-1)
		multiQ->front[y] = 0;
	else
		(multiQ->front[y])++;

	return n;
}

//prints each non empty row of the 2D array along with their FRONT and REAR values
void displayMA()
{
	int f=0;
	printf("\n");
	for(int i=0; i<SIZE; i++)
	{
		if(!isQEmpty(i))
		{
			f=1; //flag
			for(int j=0; j<MAX; j++)
			{
				if(multiQ->a[i][j] != null)
					printf("%d (%d) \t", multiQ->a[i][j], i);
			}
			printf("\nFRONT : %d\tREAR : %d\n\n", multiQ->front[i], multiQ->rear[i]);	
		}
	}	
	//if flag is 0, no non empty row was found i.e. Queue is empty
	if(!f)
		printf("Queue is Empty!\n");			
}

int main()
{
	int ch, ch1;
	int n,p,x;
	do{
	printf("\n-----\nASSUMPTIONS:\n(a) It's a CIRCULAR queue\n(b) It's a ASCENDING ORDER priority queue\n-----\n");
	printf("\nIMPLEMENT USING :\n  1. Unordered Single Array\n  2. Ordered Linked List\n  3. Multiple Arrays\nEXIT (Press 0)\nYour choice? ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 0: break;
		case 1:
		//Unordered Single Array
			printf("\nEnter the size of the queue : ");
			scanf("%d",&MAX);
			singleQ->front = -1;
			singleQ->rear = -1;
			do
			{
				printf("\n --Unordered Single Array--\nWHAT WOULD YOU LIKE TO DO?\n  1. Enqueue\n  2. Dequeue\n  3. Display Queue\nTRY ANOTHER IMPLEMENTATION (Press 0)\nYour choice? ");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 0: break;
					case 1:
						printf("\nEnter a number to enqueue : ");	scanf("%d",&n);
						printf("Enter the priority of the element : ");	scanf("%d",&p);
						if(n == null || p == null) 
						{
							printf("\nCan't store null in the queue!\n");
							break;
						}
						enqueueSA(n,p);
						break;
					case 2:
						x = dequeueSA();
						if(x!=null)
						{
							printf("\nElement %d is dequeued!",x);
							printf("\nFRONT : %d\tREAR : %d\n", singleQ->front, singleQ->rear);
						}
						break;
					case 3:
						displaySA();
						break;
					default:
						printf("\nInvalid Choice!\n");
				}
			}while(ch1!=0);
			break;

		case 2:
		//Ordered Linked List
			do
			{
				printf("\n --Ordered Linked List--\nWHAT WOULD YOU LIKE TO DO?\n  1. Enqueue\n  2. Dequeue\n  3. Display Queue\nTRY ANOTHER IMPLEMENTATION (Press 0)\nYour choice? ");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 0: break;
					case 1:
						printf("\nEnter a number to enqueue : ");	scanf("%d",&n);
						printf("Enter the priority of the element : ");	scanf("%d",&p);
						enqueueLL(n,p);
						printf("\nElement %d is inserted!\n",n);
						break;
					case 2:
						x = dequeueLL();
						if(x!=null)
							printf("\nElement %d is dequeued!\n",x);
						break;
					case 3:
						displayLL();
						break;
					default:
						printf("\nInvalid Choice!\n");
				}
			}while(ch1!=0);
			break;

		case 3:
		//Multiple Arrays
			printf("\nEnter the size of the multiple arrays : ");
			scanf("%d",&MAX);
			for(int i=0; i<SIZE; i++)
			{
				multiQ->front[i] = multiQ->rear[i] = -1;
			}
			do
			{
				printf("\n --Multiple Arrays--\nWHAT WOULD YOU LIKE TO DO?\n  1. Enqueue\n  2. Dequeue\n  3. Display Queue\nTRY ANOTHER IMPLEMENTATION (Press 0)\nYour choice? ");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 0: break;
					case 1:
						printf("\nEnter a number to enqueue : ");	scanf("%d",&n);
						printf("Enter the priority of the element (Between 0-99): ");	scanf("%d",&p);
						if(n == null || p == null) 
						{
							printf("\nCan't store null in the queue!\n");
							break;
						}
						enqueueMA(n,p);
						break;
					case 2:
						x = dequeueMA();
						if(x!=null)
							printf("\nElement %d is dequeued!\n",x);
						break;
					case 3:
						displayMA();
						break;
					default:
						printf("\nInvalid Choice!\n");
				}
			}while(ch1!=0);
			break;
		default:
			printf("\nInvalid Choice!\n");
	}
	}while(ch!=0);
	return 0;
}