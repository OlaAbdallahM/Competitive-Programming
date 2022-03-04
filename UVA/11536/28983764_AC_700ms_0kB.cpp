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
	int t; cin >> t;
	for (int c = 1; c <= t; c++) {
		reset(frq, 0);
		int n, m, k;
		cin >> n >> m >> k;
		cout << "Case " << c << ": ";
		vi v = { 1, 2, 3 };
		for (int i = 3; i < n; i++)
			v.push_back((v[i - 1] + v[i - 2] + v[i - 3]) % m + 1);
		int l, r, cnt = 0;
		for (r = 0; r < n && cnt < k; r++) {
			int val = v[r];
			cnt += (val && val <= k && !frq[val]);
			frq[val]++;
		}
		if (1 <= k && k <= 3) {
			cout << k << ed;
			continue;
		}
		else if (k>cnt) {
			cout << "sequence nai" << ed;
			continue;
		}
		l = 0;
		while (frq[v[l]] > 1 || v[l] == 0 || v[l] > k) frq[v[l++]]--;
		int ans = r - l;
		for (; r < n; r++) {
			frq[v[r]]++;

			while (v[l] == 0 || v[l] > k || frq[v[l]] > 1) {
				frq[v[l++]]--;
			}
			ans = min(ans, r - l + 1);
		}
		cout << ans << ed;
	}
	return 0;
}
