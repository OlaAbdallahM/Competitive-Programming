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
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define fr(i,l,n)for(int i=l;i<n;i++)
#define stpr(n)fixed<<setprecision(n)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 17;

int n, link[100][100], dep[100], used[100], cut_bridge[100][100];
int dfs(int node, int d, int p)
{
	int  back = 1000, tmp;
	dep[node] = d;
	fr(i, 0, n)
	{
		if (link[node][i] == 1)
		{
			if (!used[i])
			{
				used[i] = 1;
				tmp = dfs(i, d + 1, node);
				if (tmp > d)
				{
					cut_bridge[node][i] = 1;
					cut_bridge[i][node] = 1;
				}
				back = min(back, tmp);
			}
			else
			{
				if (i != p)
					back = min(back, dep[i]);
			}
		}
	}
	return back;
}
int main()
{
	fast;
	while (cin >> n)
	{
		reset(link, 0);
		reset(dep, 0);
		reset(used, 0);
		reset(cut_bridge, 0);
		fr(i, 0, n)
		{
			int u, m;char c;
			cin >> u >> c >> m >> c;
			while (m--)
			{
				int v; cin >> v;
				link[u][v] = link[v][u] = 1;
			}
		}
		fr(i, 0, n)
		{
			if (!used[i])
			{
				used[i] = 1;
				dfs(i, 1, -1);
			}
		}
		int ans = 0;
		fr(i, 0, n)
		fr(j,i+1,n)
			if (cut_bridge[i][j])
				ans++;
			cout << ans << " critical links\n";
			fr(i,0,n)
				fr(j,i+1,n)
			if (cut_bridge[i][j])
				cout << i << " - " << j << ed;
			cout << ed;
	}
}