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
vector<vi>adj;
vi viz;
int n, m,cnt; 
void dfs(int i)
{
	viz[i]++; cnt++;
	for (auto j : adj[i])
	if (!viz[j])dfs(j);
}
int main()
{
	fast;
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		adj.resize(n + 1);
		viz.resize(n + 1);
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int mx = 0;
		fr(i, 1, n + 1)
		{
			if (!viz[i])
			{
				cnt = 0;
				dfs(i);
				mx = max(mx, cnt);
			}
		}
		cout << mx << ed;
		adj.clear();
		viz.clear();
	}
}