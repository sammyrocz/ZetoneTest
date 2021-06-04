#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5

int findmin(int key[], bool visited[])
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < V; i++)
		if (visited[i] == false && key[i] < min)
			min = key[i], min_index = i;

	return min_index;
}


void printMST(int parent[], int graph[V][V])
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}


void prims(int graph[V][V])
{

	int key[V];
	int parent[V];
	bool visited[V];
 
	for (int i = 0; i < V; i++)
	{
		key[i] = INT_MAX;
		visited[i] = false;	
	}


	key[0] = 0;
	parent[0] = -1; //No parent for starting node

	for (int count = 0; count < V - 1; count++)
	{

		int k = findmin(key, visited);
		visited[k] = true;

		for (int v = 0; v < V; v++)
			if (graph[k][v] && visited[v] == false && graph[k][v] < key[v])
			{
				parent[v] = k;
				key[v] = graph[k][v];
			}
				
	}

	// Print
	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	prims(graph);

	return 0;
}

