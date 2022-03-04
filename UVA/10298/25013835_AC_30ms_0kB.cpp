#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define all(c) c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define fr(i,l,n)for(int i=l;i<n;i++)
#define stpr(n)fixed<<setprecision(n)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20;
int LP[N];   // longest prefix
char t[N];
string s, pure;
void failure_function()
{
	for (int i =1; i <sz(s); i++)
	{
		int k = LP[i];
		while (k>0 && s[k] != s[i])    //failing
			k = LP[k];
		if (s[k] == s[i])     //matching
			LP[i + 1] = k + 1;
		else
			LP[i + 1] = 0;
	}
}

int KMP()
{
	int i, k;
	for (i = 0, k = 0; i <strlen(t); i++)
	{
		while (k>0 && s[i] != t[k])
			k = LP[k - 1];
		if (s[i] == t[k])
			k++;
	}
	return k;
}

int main()
{
	fast;
	while (cin>>s)
	{
		if (s == ".")break;
		failure_function();
		int period = 0;
		fr(i, 1, sz(s) + 1)
		{
			if (i - LP[i] > period)
				period = i - LP[i];
		}
			if (sz(s) % period)
				period = sz(s);
			cout << sz(s) / period << ed;
	}
}
//????????????????????????????????!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!