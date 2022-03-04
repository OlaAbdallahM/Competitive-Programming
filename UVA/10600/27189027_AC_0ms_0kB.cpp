#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll =  long long;
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1<<10;
const ll mod = 1e9 + 7;

const int o = 200;
int cost[o][o], dist[o], lev[o], far[o][o];
bool ok[o][o],viz[o];;

void init (){
	reset(ok,0); reset(viz,0); reset(far,0);
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
				cost[i][j] = 1e9;
			cost[i][i] = 0;
		}

		for (int i = 1; i <= m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			cost[a][b] = c;
			cost[b][a] = c;
		}

		init();
		dist[1] = 0;
		viz[1] = 1;
		for (int i = 1; i <= n; i++)
		{
			lev[i]=1;
			dist[i] = cost[1][i];
		}


		/// To find the first cheapest one.
		int S1 = 0;
		while (1)
		{
			int t = -1;
			for (int i = 1; i <= n; i++)
			if ((t == -1 || dist[i] < dist[t]) && !viz[i])
				t = i;
		  if (t == -1)
			break;

			viz[t]++;
			ok[lev[t]][t] = ok[t][lev[t]] = 1;
			S1 += dist[t];

			for (int i = 1; i <= n; i++)
			{
				if (cost[t][i] < dist[i] && !viz[i])
				{
					lev[i] = t;
					dist[i] = cost[t][i];
				}
				else if (viz[i] && i != t)
				{
					far[i][t] = max(far[i][lev[t]], cost[lev[t]][t]);
					far[t][i] = far[i][t];
				}
			}
		}

		/// To find the second  cheapest one.
		int S2 = 1e9;
		for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		if (!ok[i][j] && cost[i][j] != 1e9)
			S2 = min(S2, S1 - far[i][j] + cost[i][j]);

		cout << S1 << ' ' << S2 << ed;
	}
}