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
//#define S second
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
const int mod = 1e9+7, N = 2e5, M = 5000;

struct Node{
	int cost;
	int node;
	Node(){}
	Node(int n, int c){ node = n; cost = c; }
	bool operator <(const Node & node)const{
		return cost > node.cost;
	}
};

typedef pair < int, int > ii;
vector < ii > g[100];
int  el, k;


int dist[100];

int dijkstra(){
	memset(dist, -1, sizeof(dist));
	dist[0] = 0;

	priority_queue< Node > pq;
	pq.push(Node(0, 0));
	int from, to, wt, cost;
	while (!pq.empty()){
		from = pq.top().node;
		cost = pq.top().cost;
		pq.pop();
		if (k == from) return dist[k];

		if (cost == dist[from])
		for (int i = 0; i < (int)g[from].size(); i++){
			to = g[from][i].first;
			wt = g[from][i].second;
			if (dist[to] == -1 || dist[to] > dist[from] + wt + 60){
				dist[to] = dist[from] + wt + 60;
				pq.push(Node(to, dist[to]));
			}
		}
	}
	return dist[k];
}
int main(){
	int  ind, ans;
	int T[5];
	int stops[101];
	string line;
	stringstream ss;

	while (scanf("%d %d", &el, &k) == 2){
		for (int i = 0; i < el; i++)
			scanf("%d", &T[i]);
		getline(cin, line);//clear
		for (int i = 0; i <el; i++){
			getline(cin, line);
			ss.clear();
			ss << line;
			ind = 0;
			while (ss >> stops[ind++]);
			ind--;

			for (int x = 0; x < ind; x++)
			for (int y = x + 1; y < ind; y++){
				g[stops[x]].push_back(ii(stops[y], (stops[y] - stops[x])*T[i]));
				g[stops[y]].push_back(ii(stops[x], (stops[y] - stops[x])*T[i]));
			}
		}
		ans = dijkstra();
		if (ans == -1)puts("IMPOSSIBLE");
		else{
			if (k != 0)
				ans -= 60;
			printf("%d\n", ans);
		}
		for (int i = 0; i < 100; i++) g[i].clear();
	}

	return 0;
}