#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
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
string ys = "YES", no = "NO"; const int N = 100, M = (1 << 10) + 10;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll  b){
	return(!b ? a : gcd(b, a%b));
}
ll lcm(ll n, ll m){
	return n / gcd(n, m)*m;
}



int main(){
	fast;
	
	vi p = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,43, 47 };
	ll ans = 1;
	for (auto i : p)ans *= i;
	int n;cin >> n;
	vi v(n);
	for (auto &i : v)cin >> i;
	for (int i = 1; i <= 32767; i++){
		ll val = 1;
		for (int j = 0; j<15; j++){
			if (i&(1 << j))val = val*p[j];
		}
		bool ok = 1;
		for (int i = 0; i<n; i++){
			if (gcd(v[i], val) == 1) ok = 0;
		}
		if (ok) ans = min(ans, val);
	}
	cout << ans<<ed;
}



