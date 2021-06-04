/*
Implementation of Kruskal MST Algorithm

Taking edge list as input from the user for the graph and returning
resulting edge list for the MST.
*/

#include <bits/stdc++.h>
using namespace std;

class Edge{	
	//Struct can also be used
	public:
		int source;
		int dest;
		int weight;
};

bool weight_sort(Edge e1, Edge e2)
{
	return e1.weight<e2.weight;
}

int findParent(int e, int *parent)
{
	if(parent[e]==e)
		return e;
	else
		return findParent(parent[e],parent);
}

void kruskals(Edge* input, int n, int E)
{
	//sort the edges in order of weights
	sort(input, input+E, weight_sort);
	
	Edge* mst=new Edge[n-1];
	
	int *parent = new int[n];
	for(int i=0; i<n; i++)
	{
		parent[i]=i;
	}
	
	int count=0;
	int i=0;
	while(count!=n-1)
	{
		Edge currEdge=input[i];
		
		//Check if adding this edge will lead to cycle or not
		int sourceParent=findParent(currEdge.source,parent);
		int destParent=findParent(currEdge.dest,parent);
		
		if(sourceParent!=destParent)
		{
			mst[count]=currEdge;
			parent[sourceParent] = destParent;
			count++;
		}
		i++;
	}
	
	for(i=0; i<n-1; i++)
		cout<<mst[i].source<<" "<<mst[i].dest<<" "<< mst[i].weight<<endl;
	
}

int main() {
	int n,E;
	cin>> n >> E;
	Edge * input = new Edge[E];
	
	for(int i=0; i<E; i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		input[i].source=s;
		input[i].dest=d;
		input[i].weight=w;
	}
	
	kruskals(input,n,E);
	
	return 0;
}