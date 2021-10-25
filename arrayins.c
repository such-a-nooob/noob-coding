//Insert an element in an array

#include <stdio.h>
int main()
{
    int n,a[100],i,pos,x;
	printf("\nNumber of elements in array : ");
	scanf("%d",&n);
	printf("\nEnter %d elements in array : \n",n);
	for (i=0; i<n; i++) scanf("%d",&a[i]);
	printf("\nInsert : "); scanf("%d",&x);
	printf("\nAt position : "); scanf("%d",&pos);
	if(pos>n+1) 
	{
	    printf("\nCan't insert here!");
	    return 0;
	}
	for(i=n;i>=pos;i--)
		a[i]=a[i-1];
	a[--pos]=x;
	for(i=0;i<n+1;i++)
		printf("%d\n",a[i]);
	return 0;
}