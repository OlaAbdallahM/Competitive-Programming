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
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e9 + 7, N = 1e5 + 5;

ll frq[N];
int main()
{
	fast;
	ll n, m; cin >> n >> m;
	vector<ll>v(n+1), pre(n+1);
	for (int i = 1; i <= n; i++)cin >> v[i];
	pre[0] = 0;
	for (ll i = 1; i <= n; i++)pre[i] += pre[i - 1], pre[i] += v[i];
	if (n == 1)RT(m);
	ll l = 0, r = 0, cur = 0;
	for (int i = 1; i <=n; i++){
		l = pre[i - 1];
		r = pre[n] - pre[i];
		ll ans = max(l + r + m, max(r, l));
		cout << ans << " ";
	}
	cout << ed;
	return 0;
}
