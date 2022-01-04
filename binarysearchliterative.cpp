#include<iostream>
#include<cstdlib>
using namespace std;
class Binary_Search
{
	int *arr, size,i,val,start,end;
	public:
	Binary_Search(int n)
	{
		arr=new int[n];
		size=n;
		start=0;
		end=n-1;
	}
	void insert()
	{
	    for(i=0;i<size;i++)
		{
			cout<<"Enter the value for array in index["<<i<<"]:\t";
			cin>>arr[i];
		}
		cout<<"\narray before sorting\n";
        for(i=0;i<size;i++)
        {
            cout<<"The value for array in index["<<i<<"]:\t"<<arr[i]<<endl;
        }
        int temp;
		for(i=0;i<size;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(arr[j]<arr[i])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
		cout<<"\narray after sorting\n";
        for(i=0;i<size;i++)
        {
            cout<<"The value for array in index["<<i<<"]:\t"<<arr[i]<<endl;
        }
        cout<<"\nEnter the value to be searched: ";
		cin>>val;
	}
	int search()
	{
		while(start<=end)
		{
			int mid=(start+end)/2;
			if(arr[mid]==val)
			{
				cout<<"The value is in index "<<mid;
				return 0;
			}
			else if(arr[mid]>val)
			{
				end=mid-1;
			}
			else if(arr[mid]<val)
			{
				start=mid+1;
			}

		}
		 cout<<"\nThe value is not present in array";
                return 0;
	}
};
int main()
{
	int value;
	cout<<"Enter the size of array: ";
	cin>>value;
	Binary_Search b1(value);
	b1.insert();
	b1.search();
	return 0;
}
