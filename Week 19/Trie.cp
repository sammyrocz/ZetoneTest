#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char c;
    Node* children[26] = {nullptr};
    bool isWord;
    Node(char ch) : c(ch), children(), isWord() {};
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        root = new Node('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Node* ptr = root;
        for(char ch : word)
        {
            if(ptr->children[ch-'a'] == nullptr)
                ptr->children[ch-'a'] = new Node(ch);
            ptr = ptr->children[ch-'a'];
        }
        ptr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* ptr = root;
        for(char ch : word)
        {
            if(ptr->children[ch-'a'] == nullptr)
                return false;
            ptr = ptr->children[ch-'a'];
        }
        return (ptr->isWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startswith(string prefix) {
        Node* ptr = root;
        for(char ch : prefix)
        {
            if(ptr->children[ch-'a'] == nullptr)
                return false;
            ptr = ptr->children[ch-'a'];
        }
        return true;
    }
};
int main()
{
	string a,b,c,d;
	Trie dict;
	cin>>a>>b>>c>>d;
	dict.insert(a);
	dict.insert(b);
	dict.insert(c);
	cout<<a<<" "<<dict.search(a)<<endl;
	cout<<b<<" "<<dict.startswith(b)<<endl;
	cout<<c<<" "<<dict.search(c)<<endl;
	cout<<c<<" "<<dict.startswith(c)<<endl;
	cout<<d<<" "<<dict.search(d)<<endl;
	cout<<d<<" "<<dict.startswith(d)<<endl;
	return 0;
}