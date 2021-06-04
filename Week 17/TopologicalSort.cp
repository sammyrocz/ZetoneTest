/*
Given a DAG (Directed Acyclic Graph) print any Topological Sorting of that graph.

Input format:
Two integers n & e denoting number of vertices and edges.
Then e pair of integers (a,b) follow which indicates there is an edge from a to b.
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>>&graph, 
                    vector<bool>&visited, stack<int>&stack)
{
    visited[i] = true;
  
    for (int j = 0; j < graph[i].size(); j++) 
    {
        if (!visited[graph[i][j]]) 
        {
            dfs(graph[i][j],graph,visited,stack);
        }
    }
    stack.push(i);
}
  
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int> > graph(vertices,vector<int>());
  
    int a, b;
    for (int i = 0; i < edges; i++) 
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<bool> visited(vertices, false);
    stack<int> stack;
  
    for (int i = 0; i < vertices; i++) 
    {
        if (!visited[i])
            dfs(i,graph,visited,stack);
    }

    while(!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }

    cout<<endl;
    return 0;
}