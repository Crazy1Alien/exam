#include<iostream>
#include<cstdlib>
using namespace std;
int size;
void Adjust(int a[],int i,int n)
{
    int j, item;
     j =2*i; item =a[i];
     while (j<=n)
     {
        if ((j<n) && (a[j] <a[j+1]))
        {
          j =j + 1;
        }
        if (item >=a[j])
        {
            break;
        }
        a[j/2]= a[j];
        j =2*j;
     }
        a[j/2]=item;
}
void heapify(int a[],int n)
{
    int k=0;
   for(int i=n/2;i>=0;i--)
   {
       Adjust(a,i,n);
       k++;
       cout<<"\niteration "<<k<<":\t";
       for(int l=0;l<size;l++)
       {
           cout<<a[l]<<"\t";
       }
       cout<<endl;
   }
}
void heapsort(int a[],int n)
{
    int x=0;
    heapify(a,n);
    cout<<"\nafter heapify :\t";
    for(int l=0;l<size;l++)
    {
        cout<<a[l]<<"\t";
    }
    cout<<endl;
    for(int i=n;i>=1;i--)
    {
        swap(a[i],a[0]);
        Adjust(a,0,i-1);
        x++;
        cout<<"\niteration "<<x<<":\t";
        for(int l=0;l<size;l++)
        {
           cout<<a[l]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    int n,i;
    cout<<"\nEnter n:";
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter element "<<i+1<<": ";
		cin>>a[i];
	}
	cout<<"\nBefore Sorting: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	size=n;
    heapsort(a,n-1);
    cout<<"\nAfter Sorting : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	return 0;
}

