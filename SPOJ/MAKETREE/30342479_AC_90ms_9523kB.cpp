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

int n, m,cnt, viz[N],par[N];
vector<vi>adj;
vi  intial;

void topological_sort(int i){
	viz[i] = 1;
	for (auto j : adj[i])
		if (!viz[j])
			topological_sort(j);
intial.push_back(i);
}

int main()
{
	fast;
	int n, k; cin >> n >> k;
	adj.resize(n+1);
	for (int u = 1; u <= k; u++){
		int t, v;
		cin >> t;
		while (t--){
			cin >> v;
			adj[u].push_back(v);
		}
	}
	for (int i = 1; i <= n;i++)
	if (!viz[i])topological_sort(i);

	int poz = 0;
	for (int i = n - 1; i >= 0; i--){
		int x = intial[i];
		par[x] = poz;
		poz = x;
	}
	for (int i = 1; i <= n; i++)cout << par[i] << ed;
}