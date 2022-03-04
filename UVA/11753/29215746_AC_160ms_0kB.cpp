#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18;
#define ed '\n'
#define ff first
#define ss second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;
const auto EPS = 1e-9;

int n, k;
vi v;
int dp[10001][21][21];
int solve(int i,int k1,int k2){
	int j = n - 1 - i - k1+k2;
	if (i >= j)return 0;
	int &rt = dp[i][k1][k2];
	if (~rt)return dp[i][k1][k2];
	if (k1 + k2 > k)return 100;
	if (v[i] == v[j])return rt = solve(i + 1, k1, k2);
		return rt =1+ min(solve(i, k1 + 1, k2), solve(i + 1, k1, k2 + 1));
}
int main(){
	fast; 
	int t; cin >> t;
	for(int i=1;i<=t;i++){
		cout << "Case " << i << ": ";
		cin >> n >> k;
		v.resize(n);
		for (auto&j : v)cin >> j;
		reset(dp, -1);
		int ans = solve(0,0,0);
		cout << (!ans ? "Too easy" : (ans <= k ? to_string(ans) : "Too difficult")) << ed;
	}
}