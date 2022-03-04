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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;
const auto EPS = 1e-9;


int main() {
	fast;
	vi a, b;
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		if (x)	a.push_back(x);
		else  b.push_back(y);
	}
	sort(all(a));
	sort(all(b));
	double ans = 0;
	if (sz(a))
		ans = max(ans, (double)(a.back() - a[0]));
	if (sz(b))
		ans = max(ans, (double)(b.back() - b[0]));
	if (sz(a) && sz(b)){
		long long ar[2] = { a[0], a.back() };
		long long br[2] = { b[0], b.back() };
		for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans = max(ans, sqrt(ar[i] * ar[i] + br[j] * br[j]));
	}
	cout <<stpr(6)<< ans <<ed;
	return 0;
}