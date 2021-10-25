//Check if the bishop (chess) can move between start and end in one go

#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;


int main()
{
    char start[2],end[2];
    int a,b,c,d;
    cin>>start>>end;
    a=int(toupper(start[0]))-65;    b=start[1];
    c=int(toupper(end[0]))-65;      d=end[1];
    //cin>>a>>b>>c>>d;
    if((a+b)==(c+d)||(abs(a-c)==abs(b-d)))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}