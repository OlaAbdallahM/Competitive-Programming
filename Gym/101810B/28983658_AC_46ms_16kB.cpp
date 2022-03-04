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

ll frq[1005];
int main()
{
	fast;
	int t; cin >> t;
	while (t--){
		reset(frq, 0);
		ll x; int n; cin >> x >> n;
		if (n == 1){
			cout << x << ed;
			continue;
		}
		for (int i = 1; i <= n&&x > 0; i++, x--)frq[i]++;
		ll div = x/(2 * (n - 1));
		for (int i = 2; i < n; i++)frq[i] += 2 * div;
		frq[1] += div; frq[n] += div;
		x %= 2 * (n - 1);
		for (int i = n - 1; i>0 && x > 0; i--, x--)frq[i]++;
		for (int i = 2; i <= n&&x > 0; i++, x--)frq[i]++;
		for (int i = 1; i <= n; i++)cout << frq[i] << ' ';
		cout << ed;
	}
}
