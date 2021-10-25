// reverse each word in the string

#include <stdio.h>
void reverseWord(char str[], int s, int e)
{
    int i,j,t;
	for(i=s,j=e; i<=(s+e)/2; i++,j--)  
	{
	    t= str[i];
	    str[i]=str[j];
	    str[j]=t;
	}
}
int main()
{
	char str[50];
	int s=0,e,f=0;
	printf("Enter a string : ");
	gets(str);
	for(int i=0;str[i]!='\0';i++)
	{
	    if(f!=0) s=e+2; 
	    if(str[i]==' ') 
	    {
	        e=i-1;
	        f++;
	        reverseWord(str,s,e);
	    }
	    else if(str[i+1]=='\0') 
	    {
	        e=i;
	        reverseWord(str,s,e);
	    }
	    
	}
	printf("Reverse : %s",str);

}


