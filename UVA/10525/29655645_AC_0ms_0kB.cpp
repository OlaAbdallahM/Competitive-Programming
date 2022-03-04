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
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e8+7, N = 2e5;

struct edges{
	int to, t, d;
};

vector<vector<edges>>adj;
int n, m; 

pii Dijkstra(int s, int d){

	vi minDis(n+1, INT_MAX);
	vi minTime(n+1, INT_MAX);

	set <pii> currTime;

	minTime[s] = 0;
	minDis[s] = 0;
	currTime.insert({ 0, s });

	while (!currTime.empty()){
		int nodeTime = currTime.begin()->first;
		int node = currTime.begin()->second;

		currTime.erase(currTime.begin());

		for (auto a : adj[node])
		if (a.t + nodeTime < minTime[a.to]){
			currTime.erase(make_pair(minTime[a.to], a.to));
			minTime[a.to] = a.t + nodeTime;
			minDis[a.to] = minDis[node] + a.d;
			currTime.insert(make_pair(minTime[a.to], a.to));
		}
		else if (a.t + nodeTime == minTime[a.to])
			minDis[a.to] = min(minDis[a.to], minDis[node] + a.d);
	}

	return make_pair(minDis[d], minTime[d]);
}


int main(){
	fast;
	int  T; cin >> T;
	while (T--){
		cin >> n >> m;
		adj.clear();
		adj.resize(n + 1);

		while (m--){
			int a, b, c, d; 
			cin >> a >> b >> c >> d;
			edges g; g.to = b;
			g.t = c; g.d = d;
			adj[a].push_back(g);
			g.to = a;
			adj[b].push_back(g);
		}

		int q; cin >> q;
		while (q--){
			int s, d; cin >> s >> d;
			pii ans = Dijkstra(s, d);
			if (ans.first == INT_MAX)
				cout << "No Path." << endl;
			else
				cout << "Distance and time to reach destination is " << ans.first << " & " << ans.second << "." << endl;
		}
		if (T) cout << endl;
		for (int i = 1; i <n + 1; i++)adj[i].clear();
	}
}