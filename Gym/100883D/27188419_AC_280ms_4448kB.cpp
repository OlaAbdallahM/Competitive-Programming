#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll =  long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1<<10;
const ll mod = 1e9 + 7;

int n, m;
vi v;
bool ok = 0;
void solve(int t) {
	int g = 1,mx = v[0], ext = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] > t) return ;
		mx = max(mx,v[i]);
		int val = (i - ext + 1)*mx;
		if (val > t) {
			g++;
			mx = v[i];
			ext = i;
		}
	}
	if (g <= m)ok = 1;
}

int main() {
	fast;
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;

		v.resize(n);
		for (auto &i : v) cin >> i;

		int l= 0, r = 1e9, ans=0;
		while (l<r) {
			int mid = (l+r)>>1;
			ok = 0;
			solve(mid);
			if (ok) r = mid;
			else{
				l = mid + 1;
				ans = l;
			}
		}
		cout << ans << ed;
	}
}