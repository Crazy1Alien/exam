#include <iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int mid;
void linearSearch(int a[],int x,int n,int index,int low)
{
	if(index >=n)
	{
		cout<<"The value is not present in array";
	}
    else if(a[index] == x)
	{
		cout<<"Element found"<<endl;
		cout<<"The value is in the index "<<index<<endl;
		return;
	}
	else
	{
        mid =(n + low)/2;
	    return linearSearch(a,x,n,index+1,mid+1);
		return linearSearch(a,x,mid,index+1,low);
	}
}

int main()
{

    int a[100],i,y;
    cout<<"\nEnter size of array: ";
    cin>>i;
    for(int j=0;j<i;j++){
        cout<<"\nEnter Element"<<j+1<<":";
        cin>>a[j];
    }
    //int x;
    //ifstream f("a.txt");
    //while (f.eof()!=true)
//   {
//       f>>x;
//       a[i] = x;
//       cout<<a[i]<<"\t";
//       i++;
//   }
    cout<<"\nEnter the value to be searched:\t";
    cin>>y;
    int index=0;
    linearSearch(a,y,i,index,0);
}

