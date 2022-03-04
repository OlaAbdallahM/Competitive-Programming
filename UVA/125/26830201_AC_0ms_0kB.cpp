#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;


int main()
{
	fast;
	int c = 0, n;
	while (cin >> n)
	{
		vector<vi > streets(35, vi (35, 0));
		int m = 0;

		for (int i = 1; i <= n; i++)
		{
			int u, v;
			cin >> u >> v;
			streets[u][v] = 1;
			m = max(max(u, v), m);
		}

		for (int k = 0; k <= m; k++)
		for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++)
		if (streets[i][k] && streets[k][j])
			streets[i][j] += streets[i][k] * streets[k][j];

		for (int k = 0; k <= m; k++)
			// If k -> k is a cycle, then i -> k -> j must have infinite paths.
		if (streets[k][k])
		for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++)
		if (streets[i][k] && streets[k][j])
			streets[i][j] = -1;

		cout << "matrix for city " << c++ << endl;
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				cout << (j > 0 ? " " : "")
					<< streets[i][j];
			}
			cout << endl;
		}
	}
}