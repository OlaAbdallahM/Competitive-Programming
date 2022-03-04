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

vi dfs_num, low_num, viz;
vector<vi>adj, new_adj;
int dfs_numb, num_scc;
stack<int>stk;
map<int, int>mp;
void tarjan_scc(int i)
{
	dfs_num[i] = low_num[i] = dfs_numb++;
	viz[i] = 1;
	stk.push(i);

	for (int j = 0; j<adj[i].size(); j++) {
		int v = adj[i][j];
		if (dfs_num[v] == -1) tarjan_scc(adj[i][j]);
		if (viz[v]) low_num[i] = min(low_num[i], low_num[v]);
	}

	if (low_num[i] == dfs_num[i]) {
		int v = stk.top();
		stk.pop();
		viz[v] = 0;
		mp[v] = num_scc;
		while (i != v) {
			v = stk.top();
			stk.pop();
			viz[v] = 0;
			mp[v] = num_scc;
		}
		num_scc++;
	}
}

int main()
{
	int t; cin >> t; 
	while (t--){
		int n, m;
		cin >> n >> m;
		adj.clear();
		adj.resize(n);
		mp.clear();
		while (m--)
		{
			int u, v; cin >> u >> v;
			adj[u - 1].push_back(v - 1);
		}
		// Tarjan 
		dfs_num.assign(n, -1);
		low_num.assign(n, 0);
		viz.assign(n, 0);
		dfs_numb = num_scc = 0;
		fr(i,0,n)
		if (dfs_num[i] == -1) tarjan_scc(i);
		new_adj.clear();
		new_adj.resize(num_scc);
		fr(i,0,n)
		for (int j = 0; j < sz(adj[i]);j++)
		if (mp[i] != mp[adj[i][j]])
			new_adj[mp[i]].push_back(mp[adj[i][j]]);
		vi in_degree(num_scc, 0);
		fr(i,0, num_scc)
		for (int j = 0; j < sz(new_adj[i]);j++)
			in_degree[new_adj[i][j]] = 1;
		int rt =0;
		fr(i,0,num_scc)
		if (!in_degree[i])rt++;
		cout << rt << ed;
	}
	
}