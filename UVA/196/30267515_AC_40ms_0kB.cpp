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


int n, m;
string table[1005][2000];
int ans[1005][2000];



int dfs(int x, int y)
{
	if (ans[x][y] != INT_MAX)
		return ans[x][y];
	if (table[x][y][0] != '=')
		return ans[x][y] = stoi(table[x][y]);

	int r = 0, c = 0, res = 0;
	for (int i = 1; i <= table[x][y].size(); i++)//i is equal to sheet[x][y].size will execute dfs
	{
		if (isdigit(table[x][y][i]))
			r = r * 10 + table[x][y][i] - '0';
		else
		{
			if (isalpha(table[x][y][i]))
				c = c * 26 + table[x][y][i] - 'A' + 1;
			else
			{
				res += dfs(r, c);
				r = c = 0;
			}

		}
	}
	return ans[x][y] = res;
}

int main()
{
	fast;
	int t; cin >> t;
	while (t--)
	{
		cin >> m >> n;
		string s;
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> table[i][j];
				ans[i][j] = INT_MAX;
			}
		}


		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				ans[i][j] = dfs(i, j);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (j != m)
					cout << ans[i][j] << " ";
				else
					cout << ans[i][j] << endl;
			}
		}

	}
	return 0;
}