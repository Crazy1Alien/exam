#include<iostream>
#include<cstdlib>
using namespace std;
int count=0;
int Partition(int a[],int m,int p)
{
  int v,i,j;
  v=a[m]; i=m-1 ; j=p+1;
   do
	{
        do
        {
		     i=i + 1;
		}while (a[i]<=v);
		do
        {
		     j=j - 1;
        }while (a[j]>=v);
		 if ( i < j)
         {
             if (a[i]>a[j])
                swap(a[i],a[j]);
         }
    }  while (i<=j);
    a[m]=a[j];
    a[j]=v;
    count ++;
    cout<<"\n the number of iterations: "<<count<<endl;
    for(int i=m;i<p;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	cout<<"starting value :"<<m<<endl;
	cout<<"ending value :"<<p<<endl;
    return j;
}
void QuickSort(int a[],int s,int  e)
{
    int m;
    if (s<e)
    {
        m=Partition(a,s,e);
        QuickSort(a,m+1,e);
        QuickSort(a,s,m-1);
        cout<<"value of mid: "<<m<<endl;
    }
    else{
         return;
    }
}
int main()
{
    int a[100],n,i;
    cout<<"\nEnter n:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter element "<<i+1<<": ";
		cin>>a[i];
	}
	cout<<"\n\nBefore Sorting: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
    QuickSort(a,0,n-1);
	cout<<"\n\nAfter Sorting: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}

