// https://www.interviewbit.com/problems/stepping-numbers/

#include<bits/stdc++.h>
using namespace std;

void dfs(int a,int b, vector<int> &ans,int step)
{
    if(step>=a && step<=b)
        ans.push_back(step);
        
    if(step==0 || step>b)
        return ;
        
    int last=step%10;
    int up=step*10+(last+1);
    int below=step*10+(last-1);
    
    if(last==0)
        dfs(a,b,ans,up);
        
    else if(last==9)
        dfs(a,b,ans,below);
    else
    {
        dfs(a,b,ans,below);
        dfs(a,b,ans,up);
    }
    
}

int main()
{
	int A=0;
	int B=21;
	vector<int> ans;
    for(int i=0; i<=9; i++)
        dfs(A,B,ans,i);
        
    sort(ans.begin(),ans.end());
    
    for(int i=0; i<ans.size(); i++)
    	cout<<ans[i]<<" ";
    cout<<endl;
	return 0;
}
