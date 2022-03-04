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
int di[8]={1,-1,0,0,-1,1,-1,1};
int dj[8]={0,0,1,-1,1,1,-1,-1};
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define fr(i,l,n)for(int i=l;i<n;i++)
#define stpr(n)fixed<<setprecision(n)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 17;
int par[N],rnk[N];
void make_set(int x)
{
	par[x] = x;
	rnk[x] = 0;
}
int find(int x)
{
	return (par[x] == x ? x : x=find(par[x]));
}
void Union(int x, int y)
{
	int _x = find(par[x]),
		_y=find(par[y]);
	if (_x != _y)
	{
		par[_y] = _x;
		rnk[_x] += rnk[_y];
	}
	cout << rnk[_x] << ed;
}
int main()
{
	fast;
	string s1,s2;
	int t, node, a, cnt, x, y;
	map<string, int>mp;
	cin >> t;
	while (t--)
	{
		a = cnt = 0;
		mp.clear();
		cin >> node;
		fr(i, 0, node)
		{
			cin >> s1 >> s2;
			if (mp.find(s1) == mp.end())
			{
				par[a] = a;
				rnk[a] = 1;
				mp[s1] = a++;
			}
			if (mp.find(s2) == mp.end())
			{
				par[a] = a;
				rnk[a] = 1;
				mp[s2] = a++;
			}
			x = mp[s1];
			y = mp[s2];
			Union(x, y);
		}
	}
}