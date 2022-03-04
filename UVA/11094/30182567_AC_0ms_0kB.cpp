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
const int mod = 1e9 + 7, N = 5e5 + 5, M = 1001;

int n, m;
int vis[22][22];
char grid[22][22];
char l;
int cur;

bool valid(int x) { return x >= 0 && x < n; }

int fix(int y) {
	if (y < 0) return m - 1;
	if (y >= m) return 0;
	return y;
}

void flood(int x, int y) {
	vis[x][y] = 1; cur++;
	for (int k = 0; k < 4; k++) {
		int to_x = di[k] + x;
		int to_y = fix(dj[k] + y);
		if (valid(to_x) && !vis[to_x][to_y] && grid[to_x][to_y] == l)
			flood(to_x, to_y);
	}
}

int main() {
	fast;
	while (cin >> n >> m) {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
		int x, y;
		cin >> x >> y;
		l = grid[x][y];
		flood(x, y);
		int res = 0;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		if (!vis[i][j] && grid[i][j] == l) {
			cur = 0;
			flood(i, j);
			res = max(res, cur);
		}
		cout << res << "\n";
	}
	return 0;
}