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
const int mod = 1e18, N = 1e5, M = 50000;




int main()
{
	fast;
	
	ll n;
	while (cin >> n)
	{
		if (!n)break;
		ll mx = 1;
		for (ll i = 2; i<=1e6; i++){
			if (n%i == 0){
				ll x = abs(n), cnt = 0;
				while (x%i == 0)cnt++, x /= i;
				if (x == 1){
					if ((n<0 && (cnt & 1))||(n>0))
					mx = max(mx, cnt);
				}
			}
		}
		cout << mx << ed;
	}
}