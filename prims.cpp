#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
void prims()
{
	int NOE;
	cout<<"Enter the number of Edges:";
	cin>>NOE;
	int mat[NOE][NOE],near[NOE],c[NOE],d[NOE];
	for(int i=0;i<NOE;i++)
	{
		for(int j=0;j<NOE;j++)
		{
			cout<<"Enter the cost for ["<<i<<","<<j<<"]:";
			cin>>mat[i][j];
		}
	}
	for(int i=0;i<NOE;i++)
	{
		for(int j=0;j<NOE;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	int min,k,l;
	int s;
	min=1000;
	for(int i=0;i<NOE;i++)
	{
		for(int j=0;j<NOE;j++)
		{
			if(min>mat[i][j])
			{
				min=mat[i][j];
				k=i;
				l=j;
			}
		}
	}
	cout<<"\nmin="<<min<<"\nk="<<k<<"\nl="<<l;
	for(int i=0;i<NOE;i++)
	{
		if(mat[i][l]<mat[i][k])
		{
			near[i]=l;
		}
		else
		{
			near[i]=k;
		}
	}
	cout<<"\nNear {";
	for(int i=0;i<NOE;i++)
	{
		cout<<"\t"<<near[i];
	}
	cout<<"\t}";
	near[k]=near[l]=-1;
	int min2=1000;
	for(int j=1;j<NOE-1;j++)
	{
        for(int i=1;i<NOE;i++)
        {
            if(near[i]!=-1)
            {
                c[i]=mat[i][near[i]];
                d[i-1]=i;
            }
        }
        cout<<"\nc {\t";
        for(int i=1;i<NOE;i++)
        {
            cout<<c[i]<<"\t";
        }
        cout<<"}";
        for(int i=0;i<NOE;i++)
        {
            if(c[i]!=0)
            {
                if(min2>c[i])
                {
                    min2=c[i];
                }
            }
        }
        cout<<"\nmin2="<<min2;
        for(int i=0;i<NOE-1;i++)
        {
            if(min2==c[i])
            {
                c[i]=0;
                break;
            }
        }
        for(int i=0;i<NOE-1;i++)
        {
            if(min2==mat[d[i]][near[d[i]]])
            {
                s=d[i];
                break;
            }
        }
        cout<<"\ns="<<s;
        min=min+min2;
        cout<<"\nmin="<<min;
        near[s]=-1;
        for(int i=0;i<NOE;i++)
        {
            if(near[i]!=-1 && (mat[i][near[i]]>mat[i][s]))
            {
                near[i]=s;
            }
        }
        cout<<"\nNear {";
        for(int i=0;i<NOE;i++)
        {
            cout<<"\t"<<near[i];
        }
        cout<<"\t}";
        min2=1000;
	}
}
int main()
{
	prims();
}
