#include<bits/stdc++.h>
using namespace std;

struct edge{
	int src,dst,wt;
};


void bellmanFord(vector<edge>& Edges,int V, int E)
{
	int parent[V];		
	vector<int> value(V,INT_MAX);
	
	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	for(int i=0;i<V-1;++i)
	{
		for(int j=0;j<E;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				value[V] = value[U]+wt;
				parent[V] = U;
			}
		}
	}
	//Now check by relaxing once more if we have a negative edge cycle
	for(int j=0;j<E;j++)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				cout<<"Graph has -VE edge cycle\n";
				return;
			}
		}
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
		cout<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<" from source 0 = "<<value[i]<<"\n";
}

int main()
{
	int V,E;
	cin>>V>>E;	
	vector<edge> Edges(E);

	int src,dst,wt;
	for(int i=0;i<E;++i)
	{
		cin>>src>>dst>>wt;
		Edges[i].src = src;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}

	bellmanFord(Edges,V,E);	
	return 0;
}