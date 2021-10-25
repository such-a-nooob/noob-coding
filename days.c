//Days in a month of a particular year

#include <stdio.h>
int main()
{
	int mm,yyyy,f=0,days=0;
	printf("Enter the month and the year (in mm yyyy format) : ");
	scanf("%d %d",&mm,&yyyy);
	if(yyyy%4==0 || yyyy%100==0 || yyyy%400==0) f++;
	switch(mm)
	{
		case 1:	case 3:	case 5:	case 7:	case 8:	case 10:	case 12:
		days = 31; 
		break;
		case 4:	case 6:	case 9:	case 11:
		days = 30; 
		break;
		case 2:
		if(f!=0) days = 29;
		else days=28;
	}
	printf("Days : %d",days);
}