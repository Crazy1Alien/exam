#include<iostream>
using namespace std;
int p[5];
void adjust(int a[],int i,int n){
    int j=2*i;
    int item=a[i];
    while(j<=n){
        if((j<n)&&(a[j]>a[j+1])){
            j++;
        }
        if(item<=a[j]){
            break;
        }
        a[j/2]=a[j];
        j=2*j;
    }
    a[j/2]=item;
}
void heapify(int a[],int n){
    int call=0;
    for(int i=n/2;i>=0;i--){
        adjust(a,i,n);
    }
}
int find(int i){
    while(p[i]>=0){
        i=p[i];
    }
    return i;
}
void union1(int i,int j){
    p[i]=j;
}
void getVertices(int cost[5][5],int edgeCost,int &u,int &v){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(edgeCost==cost[i][j]){
				u=j;
				v=i;
				break;
			}
		}
	}
}
int krushkals(int edgeCost[],int cost[5][5]){
    heapify(edgeCost,6);
    cout<<endl<<"After min heapify!";
    for(int i=0;i<7;i++){
        cout<<edgeCost[i]<<" ";
    }

    for(int j=0;j<5;j++){
        p[j]=-1;
    }
    int i=0,minEdgeCost,u,v,n=7,mincost=0;
    while(i<4){
    	minEdgeCost=edgeCost[i];
    	getVertices(cost,minEdgeCost,u,v);
    	edgeCost[0]=-1;
    	heapify(edgeCost,6);
    	cout<<endl<<"u = "<<u<<";v = "<<v;
    	int j=find(u);
    	int k=find(v);
    	if(j!=k){
    		i++;
    		mincost+=cost[u][v];
    		cout<<endl<<"Intermediate min: "<<mincost;
    		union1(j,k);
    		cout<<endl<<"Parent Values:";
    		for(int i=0;i<5;i++){
        		cout<<p[i]<<" ";
    		}

		}

	}
	return mincost;
}
int main(){
    int cost[5][5]={{999,6,2,7,3},{6,999,1,999,999},{2,1,999,5,999},{7,999,5,999,4},{3,999,999,4,999}};
    int edgeCost[7]={6,2,7,3,1,4,5};
    cout<<"Minimum cost: "<<krushkals(edgeCost,cost);
}
