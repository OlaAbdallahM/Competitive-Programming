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
const ll OO = 1e16;
#define ed '\n'
#define F first
//#define S second
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
string ys = "YES", no = "NO";
const long double rad = acos(-1) / 180, dgr = 180 / acos(-1);
//const int mod = 1e9 + 7, N = 2e5 + 5;

inline ll gcd(ll a, ll b) {
	if (a&&b)
	while ((a %= b) && (b %= a));
	return a^b;
}
ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)*b);
}

inline ll fast_power(ll base, ll power, ll mod)
{
	ll ans = 1;
	while (power > 0){
		if (power & 1) ans =( (__int128)ans*base) % mod;
		base = ((__int128)base*base) % mod;
		power >>= 1;
	}
	return ans;
}
ll a, b, n,mod;
inline void solve(){
	mod = a == b ?1e9+7:a-b;
	ll p = (fast_power(a, n, mod) + fast_power(b, n, mod)) % mod;
	cout << gcd(p, a - b) % int(1e9+7) << '\n';

}
int main(){
	fast;
	int t; cin >> t;
	while (t--)
	{
		 cin >> a >> b >> n;
		solve();
	}
	return 0;
}