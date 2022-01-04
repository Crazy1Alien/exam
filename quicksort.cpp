#include<iostream>
#include<cstdlib>
using namespace std;
class q_sort
{
	public:
		int Partition(int a[], int s, int e)
		{
			int key,i,j,n,t;
			key=a[e];
			i=s-1;
			for(j=s;j<=e-1;j++)
			{
				if(a[j]<=key)
				{
					i++;
					swap(a[i],a[j]);
				}
			}
			swap(a[i+1],a[j]);
			return i+1;
		}
		void QuickSort(int a[],int s,int  e)
		{
			if(s>=e)
				return;
			int m;

			m=Partition(a,s,e);
			QuickSort(a,s,m-1);
			QuickSort(a,m+1,e);
		}
};
int main()
{
	int a[1000],n,i;
	q_sort q;
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
	q.QuickSort(a,0,n-1);
	cout<<"\n\nAfter Sorting: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}


