#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
const ll OO = 0x3f3f3f3f3f3f3f3fLL;
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 5e4 + 5, M = 1 << 10;
const ll mod = 1e9 + 7;

vi v;
int dp[N];
int solve(int m){

	if (!m)return 0;
	if (m < v.back())return 1e9;

	int &rt = dp[m];
	if (~rt)return rt;

	rt = 1e9;
	for (int i = 0; i < sz(v);i++)
	if (m >= v[i])rt=min(rt,1 + solve(m - v[i]));

	return rt;
}

int main() {
	fast;
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int ans(0), r = n % 10;
		for (int i(9), j(1); i >= 0; j++, i--){
			if (r == i&&n >= 9 * j)ans = j;
		}
		cout << (!ans? "Impossible" : to_string(ans)) << ed;
	}
}