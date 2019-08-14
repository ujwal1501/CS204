#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        stack<char> s;
        string str;
        cin>>str;
        s.push('o');
        int n = str.size();
        int flag=0;
        for(int i=0; i<n; i++)
        {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<') 
                s.push(str[i]);

            if(str[i] == '|')
            {
                if(s.top() == '|') 
                    s.pop();
                else
                    s.push(str[i]);
            }
            if(str[i] == ')')
            {
                if(s.top() == '(') s.pop();
                else
                {
                    flag=flag+1;
                    i=n;
                    break;
                }
            }
            if(str[i] == '}')
            {
                if(s.top() == '{') s.pop();
                else
                {
                    flag++;
                    i = n;
                    break;
                }
            }
            if(str[i] == ']')
            {
                if(s.top() == '[') s.pop();
                else
                {
                    flag++;
                    i = n;
                    break;
                }
            }
            if(str[i] == '>')
            {
                if(s.top() == '<') s.pop();
                else
                {
                    flag++;
                    i = n;
                    break;
                }
            }
            
        }
        if(s.top() == 'o' && flag == 0) 
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
