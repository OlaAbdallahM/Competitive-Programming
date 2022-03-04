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


int main() {
	fast;
	int n, m; cin >> n >> m;
	vi a(n), b(n);
	for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
	sort(rall(a)); sort(rall(b));
	int ans = 0,w=0;
	for (int i = 0; i < n; i++)
	{
		if (b[i]<a[0])break;
		w += b[i];
		if (w >= m)	{
			ans++;
			break;
		}
		ans++;
	}
	if (w<m)
		ans +=( m-w+a[0]-1)/ a[0];
	cout << ans<<ed;
}