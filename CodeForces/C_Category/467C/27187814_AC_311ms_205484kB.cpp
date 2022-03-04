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
ll dp[5 * M][5 * M];
int n, m;
vector<ll>v;
ll solve(int i, int k){
	if (!k)return 0;
	if (i + m - 1 > n)return -1e9;
	ll &rt = dp[i][k];
	if (~rt)return rt;
	rt = solve(i + 1, k);
	return rt = max(rt, solve(i + m, k - 1) + v[i + m - 1] - v[i - 1]);
}
int main(){
	fast;
	int k;
	cin >> n >> m >> k;
	reset(dp, -1);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)cin >> v[i], v[i] += v[i - 1];
	cout << solve(1, k) << ed;
}