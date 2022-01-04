#include<iostream>
#include<cstdlib>
using namespace std;
bool place(int k,int i,int x[])
{
	for(int j=0;j<k;j++)
	{
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
		{
			return false;
		}
	}
	cout<<"\nk="<<k<<" i="<<i;
	return true;
}
void nqueens(int k, int n, int x[])
{
	for(int i=0;i<n;i++)
	{
		if(place(k,i,x)==true)
		{
			x[k]=i;
			if(k==n-1)
			{
				cout<<"\narray {\t";
				for(int j=0;j<n;j++)
				{
					cout<<x[i]<<"\t";
				}
				cout<<"}";
			}
			else
			{
				nqueens(k+1,n,x);
			}
		}
	}
}
int main()
{
	int n,k;
	int x[8];
	n=8;
	k=0;
	nqueens(k,n,x);
	return 0;
}
