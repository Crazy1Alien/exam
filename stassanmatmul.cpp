#include <iostream>
using namespace std;
int cell11(int x[4][4])
{

	return (x[0][0] * x[0][1])+ (x[0][1] * x[1][0]);
}
int cell21(int x[4][4])
{
	return (x[2][0] * x[3][1])+ (x[2][1] * x[3][0]);
}

int cell12(int x[4][4])
{
	return (x[0][2] * x[1][3])+ (x[0][3] * x[1][2]);
}

int cell22(int x[4][4])
{
	return (x[1][2] * x[0][3])+ (x[1][3] * x[0][2]);
}


int main()
{
    int a11,a12,a22,a21,b11,b12,b21,b22,P,Q,R,S,T,U,V;
    int C11,C12,C21,C22;
    int a[4][4],b[4][4],r,c;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<"enter the first matrix element["<<i<<"]["<<j<<"]:";
            cin>>a[i][j];
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<"enter the second matrix element["<<i<<"]["<<j<<"]:";
            cin>>b[i][j];
        }
    }
    a11=cell11(a);
	a12=cell12(a);
	a21=cell21(a);
	a22=cell22(a);
	b11=cell11(b);
	b12=cell12(b);
	b21=cell21(b);
	b22=cell22(b);
    P=(a11+a22)*(b11+b22);
    Q=(a21+a22)*b11;
    R=a11*(b12-b22);
    S=a22*(b21-b11);
    T=(a11+a12)*b22;
    U=(a21-a11)*(b11+b12);
    V=(a12-a22)*(b21+b22);
    C11=P+S-T+V;
    C12=R+T;
    C21=Q+S;
    C22=P+R-Q+U;
	cout<<"\n final matrix";

 	cout<<"\n"<<C11<<" "<<C12;
	cout<<"\n"<<C21<<" "<<C22;
    return 0;
}
