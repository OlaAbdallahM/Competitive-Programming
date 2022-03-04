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

int n, m, s, t;
vector < vector<pii>>adj;
int dist[int(2e4) + 4];

void dijkstra(){
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({ 0, s });
	while (sz(pq)){
		int d = pq.top().first,node=pq.top().second;
		pq.pop();
		if (d == dist[node])
		for (auto j : adj[node])
		if (j.second + dist[node] < dist[j.first]){
			dist[j.first] = j.second + dist[node];
			pq.push({ dist[j.first], j.first });
		}

	}
}

int main(){
	fast;
	int T; cin >> T;
	for (int cases = 1; cases <= T; cases++){
		cin >> n >> m >> s >> t;
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < 2e4 + 4; i++)dist[i] = 1e9;
		while (m--){
			int u, v, w; cin >> u >> v >> w;
			adj[u].push_back({ v, w });
			adj[v].push_back({ u, w });
		}

		dist[s] = 0;
		dijkstra();
		cout << "Case #" << cases << ": " << (dist[t] < 1e9 ? to_string(dist[t]) : "unreachable") << ed;
	}
}