
#include <stdio.h>

int main()
{
	int arr[100];
	int i, x, pos, n, f=0;
	
	printf("Enter the size of an array:");
	scanf("%d",&n);
	printf("Enter the elements of an array:\n");
	for(i=0; i<n;i++)
	{
		scanf("%d",&arr[i]);
		
	}

	printf("Element to be deleted : ");
	scanf("%d",&x);

    for(i=0; i<n; i++)
    {
        if(arr[i]==x) 
        {
            pos=i; f++; break;
        }
    }

    if(f==0)
        printf("%d is already missing!",x);
    else
    {
	    for (i = pos; i < n; i++)
	    	arr[i] = arr[i + 1];

	    for (i=0; i<(n-1); i++)
		    printf("%d ", arr[i]);
	    printf("\n");
    }
	return 0;
}

