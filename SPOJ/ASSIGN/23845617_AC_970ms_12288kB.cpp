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
ll n, k,mem[(1<<20)];
int main(){                  
	fast();
	int t; cin >> t;
	while (t--)
	{
		int n, v[20][20], mx;
		cin >> n;
		for (int i = 0; i < n;i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
		fill(mem, mem + (1 << n) + 1, 0);
		mem[0] = 1;
		mx = (1 << n);
		for (int mask = 0; mask < mx - 1; mask++)
		{
			int cnt = 0;
			for (int i = 0; i < n;i++)
			if (mask&(1 << i))cnt++;
			for (int i = 0; i < n;i++)
			if (v[cnt][i] == 1 && (mask&(1 << i)) == 0)
				mem[mask | (1 << i)] += mem[mask];
		}
		cout << mem[mx - 1] << ed;
	}
}
