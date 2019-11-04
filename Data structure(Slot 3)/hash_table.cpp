#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for(ll i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
//hash table with separate chaining
class Node
{
public:
    string value;
    Node* nxt;
};
class Node* createnode()
{
    Node* node = new Node;
    return node;
}
void insertb(Node** root,string x)
{
    Node* temp = createnode();
    if(*root==NULL)
    {
        *root=temp;
        temp->value=x;
        temp->nxt=NULL;
    }
    else
    {
        Node* t = *root;
        while(t->nxt!=NULL)
        {
            t=t->nxt;
        }
        t->nxt=temp;
        temp->value=x;
        temp->nxt=NULL;
    }
}
int searchl(Node* root, string key)
{
    if(root==NULL) return 0;
    Node* temp = root;
    while(temp->nxt!=NULL)
    {
        if(temp->value==key) return 1;
        temp=temp->nxt;
    }
    return 0;
}
int HashFunc(string s)
{
    int n=s.length();
    int index;
    for(int i=0; i<n; i++)
    {
        index+= ((s[i]-'a')*(i+1))%2069;
    }
    return index;
}
void insert(Node* hashtable[], string s)
{
    int index=HashFunc(s);
    insertb(&hashtable[index], s);
}
int search(Node* hashtable[], string s)
{
    int index=HashFunc(s);
    return searchl(hashtable[index], s);
}
int main()
{
    Node* hashtable[2069];
    for(int i=0;i<2069;i++)
    {
        hashtable[i]=NULL;
    }
    while(1)
    {
        int t;string s;
        cin>>t>>s;
        if(t==1)
        {
            insert(hashtable,s);
        }
        else if(t==2){
            if(search(hashtable,s)) cout<<"true\n";
            else cout<<"false\n";
        }
        else break;
    }
}
