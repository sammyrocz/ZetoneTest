#include <bits/stdc++.h>
using namespace std;

long connected;

void dfs(int i, vector<int> &visited, vector<vector<int>>& graph)
{
	visited[i]=1;
	connected++;
	for(int j=0; j<graph[i].size(); j++)
	{
		if(visited[graph[i][j]]==0)
			dfs(graph[i][j],visited,graph);
	}
}

int main() {
	//testcases count
	int t;
	cin>>t;
	
	long lib,road, vertices, edges;
	
	long i,x,y;
	
	long cost;
	
	while(t--)
	{
		cin>>vertices>>edges>>lib>>road;
		
		vector<vector<int> > graph(vertices+1,vector<int>());
		vector<int> visited(vertices+1);
		
		for(i=0; i<edges; i++)
		{
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
	
	
	for(i=1; i<=vertices; i++)
		visited[i]=0;
		
	cost=0;
		
	if(lib<road)
		cost=lib*vertices;
	else
	{
		for(i=1; i<=vertices; i++)
		{
			if(visited[i]==0)
			{
			connected=0;
			dfs(i,visited,graph);
			cost+=lib;
			cost+=(connected-1)*road;
			}
		}
	}
	
	cout<<cost<<endl;
	}
	
	return 0;
}