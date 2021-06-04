// https://www.interviewbit.com/problems/word-ladder-i/

#include <bits/stdc++.h>
using namespace std;

int wordladder(string source, string target, vector<string> &d)
{
	if(source==target)
		return 0;
	
	int ans=0;
	queue<string> q;
	q.push(source);
	
	while(!q.empty())
	{
		ans++;
		
		int size=q.size();
		for(int i=0; i<size;i++)
		{
			string word=q.front();
			q.pop();
			
			for(int pos=0; pos<word.length(); pos++)
			{
				char org=word[pos];
				for (char c='a'; c<='z'; c++)
				{
					word[pos]=c;
					
					if(word==target)
						return ans+1;
					
					if(find(d.begin(),d.end(),word) == d.end())
						continue;
					d.erase(find(d.begin(),d.end(),word));
					q.push(word);
				}
				word[pos]=org;
			}
		}
	}
	
	return 0;
}

int main() {
	vector<string> d;
	d.push_back("hot");
	d.push_back("dot");
	d.push_back("dog");
	d.push_back("lot");
	d.push_back("log");
	string source="hit";
	string target="cog";
	d.push_back(target);
	cout<<wordladder(source,target,d);
	return 0;
}