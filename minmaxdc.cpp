#include <iostream>
#include <limits>
using namespace std;

void maxmin_divide_and_conquer(int arr[], int start, int stop, int &min, int & max)
{
    if (start == stop)
    {
        min = max = arr[start];
    }
    else if (start + 1 == stop)
    {
        if (arr[start] <  arr[stop])
        {
            max = arr[stop];
            min = arr[start];
        }
        else
        {
            max = arr[start];
            min = arr[stop];
        }
    }
    else
    {
        int midpoint = (start + stop) / 2;
        int leftMin;
        int leftMax;
        int rightMin;
        int rightMax;

        maxmin_divide_and_conquer(arr, start, midpoint, leftMin, leftMax);
        maxmin_divide_and_conquer(arr, midpoint + 1, stop, rightMin, rightMax);

        if (leftMin < rightMin)
            min = leftMin;
        else
            min = rightMin;

        if (leftMax > rightMax)
            max = leftMax;
        else
            max = rightMax;
    }
}

int main()
{
    int size;
    cout<<"Enter number of elements: ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the element no "<<i+1<<": ";
        cin>>arr[i];
    }

    int min;
    int max;
    maxmin_divide_and_conquer(arr, 0, size - 1, min, max);

    cout << "Divide and Conquer recursive --- " << '\n';
    cout << "Minimum is: " << min << '\n' << "Maximum is: " << max << "\n\n";

    return 0;
}
