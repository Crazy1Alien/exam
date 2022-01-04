#include<iostream>
#include<cstdlib>
using namespace std;
class Linear_Search
{
	int *arr, val, size,i,count;
	public:
		Linear_Search(int n)
		{
			arr=new int[n];
			size=n;
		}
		void input()
		{
		   for(i=0;i<size;i++)
			{

				cout<<"Enter the values of array for index["<<i<<"]:\t";
				cin>>arr[i];
			}
			cout<<"Enter the value to be searched:\t";
			cin>>val;
		}
		int search()
		{
			count=0;
			for(i=0;i<size;i++)
			{
				if(arr[i]==val)
				{

					count++;
					return 0;
				}
			}
		}
		void display()
		{
		    if(count!=0)
            {
                cout<<"The value is in the index "<<i<<endl;
            }
            else
            {
                cout<<"The value is not present in array";
            }
		}
};
int main()
{
	int x;
	cout<<"Enter the size of array: ";
	cin>>x;
	Linear_Search l1(x);
	l1.input();
	l1.search();
    l1.display();
	return 0;
}
