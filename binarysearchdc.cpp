#include <iostream>
using namespace std;
int binarySearch(int a[], int low, int high, int target)
{
    if (low > high) {
        return -1;
    }
    int mid = (low + high)/2;    
    if (target == a[mid]) {
        return mid;
    }
    else if (target < a[mid]) {
        return binarySearch(a, low, mid - 1, target);
    }
    else {
        return binarySearch(a, mid + 1, high, target);
    }
}
 
int main(void)
{
    int n;
    cout<<"\nEnter size of array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter element "<<i+1<<":";
        cin>>a[i];
    }
    int target;
    cout<<"\nEnter Number to be Searched :";
    cin>>target;
    int index = binarySearch(a, 0, n-1, target);
 
    if (index != -1) {
        cout<<"Element found at index :"<< index;
    }
    else {
        cout<<"Element not found in the array";
    }
 
    return 0;
}