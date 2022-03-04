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
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define show(x) cout << (#x)<<" = "<<x<<ed
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
const int N = 5e5;
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
struct edg{
	int x, y, w, enable;
};
edg E[10005];
bool cmp(edg a, edg b)
{
	return a.w < b.w;
}
int par[105], Sz[105];
void init(int n)
{
	static int i;
	for (int i = 0; i <= n; i++)
		par[i] = i, Sz[i] = 1;
}
int find_par(int x)
{
	return (x == par[x] ? x : par[x]=find_par(par[x]));
}
int merge(int x, int y)
{
	x = find_par(x);
	y = find_par(y);
	if (x != y)
	{
		if (Sz[x] > Sz[y])
		{
			Sz[x] += Sz[y];
			par[y] = x;
		}
		else
		{
			Sz[y] += Sz[x];
			par[x] = y;
		}
		return 1;
	}
	return 0;
}
int main(){
	fast();
	int t,n, m, x, y, w;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++)
	{
		cin >> n >> m;
		for (int i = 0; i < m;i++)
		{
			cin >> x >> y >> w;
			E[i].x = x; E[i].y = y;
			E[i].w = w; E[i].enable = 0;
		}
		cout <<"Case #" <<cnt<<" : ";
		sort(E, E + m, cmp);
		int cost = 0, ontree[105], idx = 0;
		init(n);
		for (int i = 0; i < m; i++)
		{
			if (merge(E[i].x, E[i].y))
			{
				cost += E[i].w;
				ontree[idx++] = i;
			}
		}
		if (idx != n - 1)
		{
			cout<<"No way\n";
			continue;
		}
		int mn_cost = 0xfffffff;
		for (int i = 0; i < idx; i++)
		{
			cost = 0;
			E[ontree[i]].enable = 1;
			init(n);
			int c = 0;
			for (int j = 0; j < m; j++)
			{
				if (!E[j].enable&&merge(E[j].x, E[j].y))
				{
					cost += E[j].w;
					c++;
				}
			}
			E[ontree[i]].enable = 0;
			if (mn_cost>cost&&c == n - 1)
				mn_cost = cost;
		}
		if (mn_cost == 0xfffffff)
			cout<<"No second way\n";
		else
			cout << mn_cost << ed;
	}
}