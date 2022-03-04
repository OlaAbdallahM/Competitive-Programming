#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18;
#define ed '\n'
#define EPS 1e-12
#define PI acos(-1.0)
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
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e9 + 7, N = 5e5 + 5, M = 5005;

int g[512][512], indeg[512];
int n;
void bfs() {
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0)
			Q.push(i);
	}
	int r[512], rt = 0, u;
	while (!Q.empty()) {
		u = Q.front(), Q.pop();
		r[rt++] = u;
		for (int i = 1; i <= n; i++) {
			if (g[u][i]) {
				if (--indeg[i] == 0)
					Q.push(i);
			}
		}
	}
	if (rt != n) {
		puts("IMPOSSIBLE");
		return;
	}
	for (int i = 0; i < n; i++) {
		cout<< r[i]<<( i == n - 1 ? '\n' : ' ');
	}
}
int main() {
	int t, rnk[512];
	int  m, x, y;
	cin>>t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin>>rnk[i];

		for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			g[i][j] = 0;
		for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			g[rnk[i]][rnk[j]] = 1;

		 cin>>m;
		for (int i = 0; i < m; i++) {
			cin>>x>>y;
			swap(g[x][y], g[y][x]);
		}

		for (int i = 1; i <= n; i++) {
			indeg[i] = 0;
			for (int j = 1; j <= n; j++)
				indeg[i] += g[j][i];
		}
		bfs();
	}
	return 0;
}