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
const int mod = 1e18, N = 2e5, M = 50000;

vi v;
bool ok(int md){
	if (v[0] > md)return 0;
	if (v[0] == md)md--;
	for (int i = 1; i < sz(v); i++){
		int dif = v[i] - v[i - 1];
		if (dif == md)md--;
		else if (dif>md)return 0;
	}
	return  1;
}
int main() {
	fast;
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cout << "Case " << tc << ": ";
		int n; cin >> n;
		v.resize(n);
		for (auto&i : v) cin >> i;
		int l = 1, r= 1e9,ans = 0;
		while (l<= r) {
			int md = (l + r)>>1;
			if (ok(md)) {
				ans = md;
				r = md - 1;
			}
			else l = md + 1;
		}
		cout << ans << ed;;
	}
	
}