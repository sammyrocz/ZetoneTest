/*
https://practice.geeksforgeeks.org/problems/alien-dictionary/1

Given the order in which words occur in the dictionary of an Alien language, find the 
order between the alphabets.
*/#include<bits/stdc++.h>
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
    int n, k;
    cin >> n >> k;
    
    string dictionary[n];
    vector<vector<int>>graph(k);
  
    for (int i = 0; i < n; i++) 
    {
        cin>>dictionary[i];
    }

    for(int i=0;i<n-1;i++)
    {
        string w1 = dictionary[i] , w2 = dictionary[i+1];
        
        for(int j=0;j<min(w1.length(), w2.length());j++)
        {
            if(w1[j] != w2[j])
            {
                graph[w1[j]-'a'].push_back(w2[j]-'a');
                break;
            }
        }
    }
    
    int vertices=k;

    vector<bool> visited(vertices, false);
    stack<int> stack;
  
    for (int i = 0; i < vertices; i++) 
    {
        if (!visited[i])
            dfs(i,graph,visited,stack);
    }

    while(!stack.empty())
    {
        cout<<char('a' + stack.top())<<" ";
        stack.pop();
    }

    cout<<endl;
    return 0;
}