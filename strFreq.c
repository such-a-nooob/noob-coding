//Frequency of a character in a string

#include <stdio.h>
int main()
{
	int f=0;
	char str[50],ch;
	printf("Enter a string : "); gets(str);
	printf("Enter a character to find its Frequency : "); scanf("%c",&ch);
	for(int i=0;str[i]!='\0';i++) if(str[i]==ch) f++;
	printf("Frequency : %d\n",f);	
	return 0;

}