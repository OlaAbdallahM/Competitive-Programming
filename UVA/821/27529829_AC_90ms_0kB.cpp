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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;

int adj[105][105];
bool on[105];

int main(){
	fast;
	int cnt = 1;

	while (true) {
		reset(adj,63);
		reset(on,0);

		int u, v; cin >> u >> v;
		if (!u&&!v)
			break;

		while (true) {
			on[u] = true;
			on[v] = true;
			adj[u][v] = 1;

			cin >> u >> v;
			if (!u&&!v)
				break;
		}

		for (int k = 0; k < 105; k++)
		for (int i = 0; i < 105; i++)
		for (int j = 0; j < 105; j++)
			adj[i][j] = min(adj[i][j],
			adj[i][k] + adj[k][j]);

		double ans = 0, nans = 0;
		for (int i = 0; i < 105; i++) {
			for (int j = 0; j < 105; j++) {
				if (i == j)
					continue;
				if (on[i] && on[j]) {
					ans += adj[i][j];
					nans++;
				}
			}
		}

		cout <<stpr(3)<< "Case " << cnt++ << ": average length between pages = " << ans / nans << " clicks\n";
	} 
}