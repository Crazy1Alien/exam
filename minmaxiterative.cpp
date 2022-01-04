#include<iostream>
#include<conio.h>
using namespace std;
int minmax()
{
    int num;
    cout<<"\nEnter the number of elements: ";
    cin>>num;
    int a[num];
    int Min,Max;
    for(int i=0;i<num;i++)
    {
        cout<<"\nEnter "<<i+1<<" element: ";
        cin>>a[i];
    }
    Min=Max=a[0];
    for(int j=1;j<num;j++)
    {
         if (a[j] > Max)
            Max = a[j];
        else if (a[j] < Min)
            Min = a[j];
    }
    cout<<"The Max is:"<<Max<<endl;
    cout<<"The Min is:"<<Min<<endl;
}
int main()
{
    minmax();
    return 0;
}
