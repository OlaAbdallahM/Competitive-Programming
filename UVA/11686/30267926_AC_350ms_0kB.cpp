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

int cnt, viz[N], par[N];
vector<vi>adj;
vi  intial;
bool ok;
void topological_sort(int i,int par){
	viz[i] = 1;
	for (auto j : adj[i])
	if (!viz[j])
		topological_sort(j,par);
	else if (j == par){ ok = 0; return; }
	intial.push_back(i);
}

int main()
{
	fast;
	int n, k; 
	while (cin >> n >> k){
		if (!n&&!k)break;
	
		adj.resize(n + 1);
		for (int i = 1; i <= n;i++)
		adj[i].clear();
		intial.clear();
		reset(viz, 0);

	   while (k--){
		   int u, v; 
		cin >> u>>v;
		adj[u].push_back(v);
		}
	   ok = 1;
		for (int i = 1; i <= n; i++)
		if (!viz[i])topological_sort(i,i);

		if (!ok)cout << "IMPOSSIBLE\n";
		else 
		for (int i = n - 1; i >= 0; i--)
			cout << intial[i] << ed;
		//cout << ed;
	}
	
}