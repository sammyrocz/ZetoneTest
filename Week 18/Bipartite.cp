#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<vector<int>>& graph, int v)
{
	int color[v];
	int i;
	int curr;
	
	for(i=0; i<v; i++)
		color[i]=-1;
	
	color[0]=1;
	
	queue<int> q;
	q.push(0);
	
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		
		for(i=0; i<graph[node].size(); i++)
		{
			curr=graph[node][i];
			if(color[curr]==-1)
			{
				color[curr]=1-color[node];
				q.push(curr);
			}
			else if(color[curr]==color[node])
			{
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	int vertices, edges;
 
	int i,x,y;
 
	cin>>vertices>>edges;

	vector<vector<int> > graph(vertices,vector<int>());
	// vector<int> visited(vertices+1);

	for(i=0; i<edges; i++)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	if(bipartite(graph,vertices))
		cout<<"Yes";
	else
		cout<<"False";
	
	return 0;
}