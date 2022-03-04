#define _CRT_SECURE_NO_WARNINGS
//            Allah_Almost3aan       
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
const ll OO=1e18;
#define INF 1e9+7
#define ed "\n"
#define ff first
#define ss second
#define sz(a) a.size()
#define RT(v) return cout<<v<<ed,0
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define stpr(n) fixed<<setprecision(n)
int di[8] = {1,0,-1,0,-1,1,-1,1};
int dj[8] = {0,-1,0,1,1,1,-1,-1};
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);}
ll fast_power(ll base, ll power,ll mod)
{
	ll ans = 1;
	while (power > 0){
		if (power & 1) ans = (ans*base) % mod;
		base = (base*base) % mod;
		power >>= 1;
	}
	return ans;
}
int main(){
	fast();
	ll b, p, m;
	while (cin >> b >> p >> m)
	{
		cout << fast_power(b, p, m) << ed;
	}
}
	