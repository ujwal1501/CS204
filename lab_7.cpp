
#include <bits/stdc++.h>
#define lli long long int
#define endl "\n"

using namespace std;
 
 bool compare(string s1,string s2)
 { 
   string s3=s1+s2,s4=s2+s1;
   return s3>s4;
 }

int main() 
{ 
 
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector <string> s(n);
    for(int i=0;i<n;i++)
    	{
    		cin>>s[i];
    	}
    sort(s.begin(),s.end(),compare);
    for(int i=0;i<n;i++)
    	{
    		cout<<s[i];
    	}
    cout<<"\n";
  }
  return 0; 	
}