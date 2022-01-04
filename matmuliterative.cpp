#include <iostream>
using namespace std;
int matmulti(int a[10][10], int b[10][10],int r1,int r2, int c1,int c2)
{
        int mul[r1][c2];
        cout<<"multiply of the matrix=\n";
        for(int i=0; i<r1; i++)
        {
            for(int j=0; j<c2; j++)
            {
                int sum =0;
                for(int k=0; k<r2; k++)
                {
                    sum += (a[i][k] * b[k][j]);
                }
                mul[i][j] = sum;
            }
        }
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            {
                cout<<mul[i][j]<<" ";
            }
            cout<<"\n";
        }
        return 0;
}
int main()
{
    int a[10][10],b[10][10],r1,c1,r2,c2;
    cout<<"enter the number of row for first matrix=";
    cin>>r1;
    cout<<"enter the number of column for first matrix=";
    cin>>c1;
    cout<<"enter the number of row for second matrix=";
    cin>>r2;
    cout<<"enter the number of column for second matrix=";
    cin>>c2;

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cout<<"enter the first matrix element["<<i<<"]["<<j<<"]:";
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<"enter the second matrix element["<<i<<"]["<<j<<"]:";
            cin>>b[i][j];
        }
    }
    if(r2==c1)
    {
        matmulti(a,b,r1,r2,c1,c2);
    }
    else
    {
        cout << "Matrix  multiplaction Not possible for the given matrices";
    }
    return 0;
}
