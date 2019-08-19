#include<bits/stdc++.h>

using namespace std;

struct treenode
{
    int i;
    treenode* left,* right,* parent;
};

int chprec(char c)
{
    if(c=='+')
    return -1;
    else if(c=='-')
    return -2;
     else if(c=='*')
    return -3;
     else if(c=='/')
    return -4;
     else if(c=='^')
    return -5;
    
  
}
int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

bool ischar(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^'){
    return true;}

    return false;
}


stack<int> postfix(char *s)
{
    stack<int> S,O;
    int f=0,a;
    O.push('N');
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                a=S.top();
                S.pop();
                S.push(a*10+s[i]-'0');
            }
            else
            {
                S.push(s[i]-'0');
                f=1;
            }
        }

        else
        {
            f=0;
            if(s[i]=='(')
                O.push('(');
            else if(s[i]==')')
            {
                while(O.top()!='N'&&O.top()!='(')
                {
                    char c=O.top();
                    O.pop();
                    S.push(chprec(c));
                }
                if(O.top()=='(')
                    O.pop();
            }
            else if(ischar(s[i]))
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<=prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push(chprec(c));
                }
                O.push(s[i]);
            }
        }
    }
    while(O.top()!='N')
        {
            char c=O.top();
            O.pop();
            S.push(chprec(c));
        }
    return S;
}

treenode * newNode(int v)
{
    treenode * temp=new treenode;
    temp->left = NULL;
    temp->right = NULL;
    temp->i = v;
    return temp;
}

treenode * etree(stack<int> s)
{
    treenode *t,*t1,*t2;
    
    stack<treenode *> st;
    while(!s.empty())
    {
        if(s.top()>=0)
        {
            t=newNode(s.top());
            s.pop();
            st.push(t);
        }
        else
        {
            t=newNode(s.top());
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();

            t->right=t1;
            t->left=t2;

            st.push(t);
            s.pop();
        }
    }
    return t;
}


void show(stack<int> s)
{
    while(!s.empty())
    {
        int a=s.top();
        s.pop();
        cout<<a<<endl;
    }
}

void Inorder(struct treenode* node)
{
    if (node == NULL)
        return;

     Inorder(node->left);

    
    cout << node->i << " ";

    
    Inorder(node->right);
}




int eval(treenode* root)
{
    
    if (!root)
        return 0;

    
    if (!root->left && !root->right)
        return root->i;

    
    int l_val = eval(root->left);

    
    int r_val = eval(root->right);

    
    if (root->i==-1)
        return l_val+r_val;

    if (root->i==-2)
        return l_val-r_val;

    if (root->i==-3)
        return l_val*r_val;

    if(root->i==-4)
        return l_val/r_val;
    return pow(l_val,r_val);
}


int main()
{
    
    int T;
    cin>>T;
    while(T--)
    {
        char s[50000];
        cin>>s;
        stack <int> S,s1;
        S=postfix(s);
        while(!S.empty())
        {
            s1.push(S.top());
            S.pop();
        }
        
        treenode *p=etree(s1);
        
        cout<<eval(p)<<endl;
        
    }
}    