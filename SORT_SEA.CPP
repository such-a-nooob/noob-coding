#include<iostream.h>
#include<conio.h>
void s_sort(int a[],int n);
void b_sort(int a[],int n);
int b_search(int a[],int n,int x);
int l_search(int a[],int n,int x);
void main()
{
clrscr();
int a[50],i,n,ch,x;
char c;
cout<<"Enter the number of terms in array ";
cin>>n;
cout<<"\nEnter "<<n<<" numbers in array ";
for(i=0;i<n;i++)
cin>>a[i];
do
{
clrscr();
cout<<"\nEntered array is \n";
for(i=0;i<n;i++)
cout<<a[i]<<"\t";
cout<<endl;
cout<<"\n\n***MENU***\n1.\tBubble sort\n2.\tSelection sort\n3.\tLinear search\n4.\tBinary search";
cout<<"\nEnter your choice ";
cin>>ch;
switch(ch)
{
case 1:
b_sort(a,n);
cout<<"\nSorted array is \n";
for(i=0;i<n;i++)
cout<<a[i]<<'\t';
break;
case 2:
s_sort(a,n);
cout<<"\nSorted array is \n";
for(i=0;i<n;i++)
cout<<a[i]<<'\t';
break;
case 3:
cout<<"\nEnter the number to be searched: ";
cin>>x;
if(l_search(a,n,x))
cout<<x<<" is present in the array "<<endl;
else
cout<<x<<" is not present in the array "<<endl;
break;
case 4:
cout<<"\nEnter the number to be searched: ";
cin>>x;
if(b_search(a,n,x))
cout<<x<<" is present in the array "<<endl;
else
cout<<x<<" is not present in the array "<<endl;
break;
default: cout<<"\n Invalid choice ";
}
cout<<"\n Want to continue? (y/n) ";
cin>>c;
}while(c=='y'||c=='Y');
getch();
}
void b_sort(int a[],int n)
{
int t;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-1-i;j++)
{
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
}
void s_sort(int a[],int n)
{
int t;
for(int i=0;i<n;i++)
{
for(int j=i;j<n;j++)
{
if(a[i]>a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
}
int b_search(int a[],int n,int x)
{
b_sort(a,n);
int m,l=n,s=0,f=0;
while(m>=0)
{
m=(s+l)/2;
if(a[m]>x)
l=m;
else if(a[m]<x)
s=0;
else if(a[m]==x)
f++;
}
return f;
}
int l_search(int a[],int n,int x)
{
int f=0;
for(int i=0;i<n;i++)
{
if(a[i]==x)
f++;
}
return f;
}

