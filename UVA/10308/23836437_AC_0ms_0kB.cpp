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
const int N = 1e4 + 4;
vector<vector<pii>>adj;
int vis[N],u,v,w;
ll ans1, mxcost, lastnode;
pii diameter(int i, int par = -1)
{
	int diam = 0;
	int mx_h[3] = { 0, 0, 0 };
	for (auto j : adj[i])
	if (j.ff != par)
	{
		pii p = diameter(j.ff, i);
		diam = max(diam, p.ff);
		mx_h[0] = p.ss + j.ss;
		sort(mx_h, mx_h + 3);
	}
	diam = max(diam, mx_h[1] + mx_h[2]);
	return{ diam, mx_h[2] };
}
void get(string s)
{
	string s1 = s.substr(0, s.find(' '));
	s.erase(0, s.find(' ') + 1);
	for (auto i : s1){
		u *= 10; u += (i - '0');
	}
	 s1 = s.substr(0, s.find(' '));
	s.erase(0, s.find(' ') + 1);
	for (auto i : s1){
		v *= 10; v += (i - '0');
	}
	for (auto i : s){
		w *= 10; w+= (i - '0');
	}
}
int main(){
	fast();
	string s;
	while (1){
		int cnt = 0;
		adj.resize(N);
		while (getline(cin,s))
		{
			if (!sz(s)) break;
			u = 0, v = 0, w = 0;
			get(s);
		//	cout<<u<<" * "<<v<<" * "<<w<<ed;
			adj[u].push_back({ v, w });
			adj[v].push_back({ u, w });
			cnt++;
		}
		if (!cnt)return 0;
		cout << diameter(1).ff << ed;
		memset(vis, 0, sizeof vis);
		adj.clear();
	}
}