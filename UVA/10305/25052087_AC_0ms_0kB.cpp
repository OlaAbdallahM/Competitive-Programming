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

vector< vector<int> > adj;
vector<bool> viz;
vector<int> topsort;

void dfs(int node)
{
	viz[node] = true;
	for(auto j:adj[node])
		if (!viz[j])	// To avoid cyclic behavior
			dfs(j);
	topsort.push_back(node);	// DAG // Other way Indegree / Outdegree
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (!n&&!m)break;
		adj.resize(n + 1);
		viz.resize(n + 1);
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		fr(i, 1, n + 1)if (!viz[i])dfs(i);
		reverse(all(topsort));
		for (auto i : topsort)cout << i << ' ';
		fr(i, 1, n + 1)if (!viz[i])cout << i << ' ';
		cout << ed;
		fr(i,1,n+1)adj[i].clear();
		topsort.clear();
		viz.clear();
	}
	return 0;
}
//????????????????????????????????!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!