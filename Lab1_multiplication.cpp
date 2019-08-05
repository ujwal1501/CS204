#include<bits/stdc++.h>
using namespace std;


string findSum(string str1, string str2)
{
	int n1 = str1.length(), n2 = str2.length();
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	if(n2>=n1)
	{string str = "";

	int carry = 0;
	for (int i=0; i<n1; i++)
	{

		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');

		carry = sum/10;
	}

	for (int i=n1; i<n2; i++)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}


	if (carry)
		str.push_back(carry+'0');


	reverse(str.begin(), str.end());

	return str;}

	if(n1>n2)
	{string str = "";

	int carry = 0;
	for (int i=0; i<n2; i++)
	{

		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');

		carry = sum/10;
	}

	for (int i=n2; i<n1; i++)
	{
		int sum = ((str1[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}


	if (carry)
		str.push_back(carry+'0');


	reverse(str.begin(), str.end());

	return str;}

}



int main()
{   int n;
    cin>>n;
    string arr[n];
    for(int w=0;w<n;w++)
    {
    string s1;
    string s2;
    cin>>s1>>s2;
    int n1=s1.length();
    int n2=s2.length();
    reverse(s1.begin(), s1.end());
    string total1="";
    for(int i=0;i<n2;i++)
    {    string stt="";
         int carry1=0;
        for(int j=0;j<n1;j++)
        {
            int mul=(s1[j]-'0')*(s2[i]-'0')+carry1;
            carry1= mul/10;
            stt.push_back((mul%10)+'0');

        }
        if(carry1)
            stt.push_back(carry1+'0');

        reverse(stt.begin(), stt.end());

        for(int k=(n2-1);k>i;k--)
            stt.push_back('0');

        total1=findSum(total1,stt);
    }
    arr[w]=total1;}
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<'\n';
    }
    return 0;
}
