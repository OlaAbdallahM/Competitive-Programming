#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N =1<<20, M = 1 << 10;

int n,m, dist[M];
vector<int> adj[M];


int main() {
	fast;
	int t; 	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n;i++) {
			adj[i].clear();
			dist[i] = 1e9;
		}
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		queue<int> q;
		q.push(0);
		dist[0] = 0;
		while (sz(q)) {
			int u = q.front(); q.pop();
			for (auto i : adj[u])
			if (dist[i] == 1e9) {
				dist[i] = dist[u] + 1;
				q.push(i);
			}
		}

		for (int i = 1; i < n; i++)cout << dist[i] << ed;
		if (t)cout << ed;
	}
}