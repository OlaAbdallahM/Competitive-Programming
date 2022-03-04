#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan 
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using  ll = long long;
const ll OO = 1e18;
#define MOD 1e9+7
#define fnt 0x3f3f3f3f
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
vector<string>v;
int n, m,ans;
int dist[25][25],mem[1<<16+5][16];
vector<pii>nuts;
int sol(int mask, int pos)
{
	int cnt = 0;
	for (int i = 0; i < 16;i++)
	if (mask&(1 << i))cnt++;
	if (cnt == sz(nuts)) return dist[pos][0];
	int &rt = mem[mask][pos];
	if (~rt)return rt;
	rt = INT_MAX;
	for (int i = 0; i < sz(nuts); i++)
	if (!(mask&(1 << i)))
		rt = min(rt, dist[pos][i] + sol((mask|(1 << i)), i));
	return rt;
}
int main(){   // LIS
	fast();
	while (cin >> n >> m)
	{
		v.clear();
		v.resize(n);
		nuts.clear();
		int x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			for (int j = 0; j < m; j++)
			if (v[i][j] == 'L')
				nuts.push_back({ i, j });
		}
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		if (v[i][j] == '#')
			nuts.push_back({ i, j });
		memset(dist, 0, sizeof dist);
		for (int i = 0; i < sz(nuts); i++)
		for (int j = 0; j < sz(nuts); j++)
			dist[i][j] = dist[j][i] = max(abs(nuts[i].ff - nuts[j].ff), abs(nuts[i].ss - nuts[j].ss));

		memset(mem, -1, sizeof mem);
		cout << sol(1, 0) << ed;
	}
}
