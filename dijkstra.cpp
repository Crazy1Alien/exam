#include<iostream>
using namespace std;
void dijkstra(int u,int cost[5][5],int dist[],int n)
{
    bool s[5];
    for(int i=0;i<n;i++)
    {
        s[i]=false;
        dist[i]=cost[u][i];
    }
    s[u]=true;
    dist[u]=0;
    int j=0;
    for(int num=1;num<n;num++)
    {
        s[u]=true;
        int w=u;
        while(cost[w][j]!=999 && s[w]!=false)
        {
            if(dist[w]>dist[u]+cost[u][w])
            {
                dist[w]=dist[u]+cost[u][w];
            }
            j++;
            w++;
        }
        s[w]=true;
    }
    int max=dist[0];
    cout<<"\nmax1="<<max;
    cout<<"\ndist {\t";
    for(int i=0;i<n;i++)
        cout<<dist[i]<<"\t";
    cout<<"}";
    for(int i=0;i<n;i++)
    {
        if(dist[i]>max && dist[i]!=999)
        {
            max=dist[i];
            cout<<"\nmax="<<max;
        }
    }
    cout<<"\nTotal distance from source to destination is: "<<max;
}
int main()
{
    int cost[5][5]={{999,1,8,999,999},{999,999,999,2,999},{7,999,999,3,4},{999,999,999,999,5},{999,6,2,999,999}};
    int dist[5]={0,0,0,0,0};
    int u=0;
    dijkstra(u,cost,dist,5);
}
