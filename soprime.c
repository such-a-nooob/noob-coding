//To check if a number is a sum of prime numbers

#include <stdio.h>
int main()
{
	int n,f1=0,f2=0;
	printf("Enter a number : ");
	scanf("%d",&n);
	for (int i=3; i<=n/2; i++)
	{
		f1=0; f2=0;
		for(int j=1; j<=i; j++)
			if(i%j==0) f1++;
		//if((n-i)<i) break;
		for(int j=1; j<=(n-i); j++)
			if((n-i)%j==0) f2++;
		if(f1==2 && f2==2) 
			printf("%d = %d + %d \n",n,i,n-i);
	}
	return 0;
}