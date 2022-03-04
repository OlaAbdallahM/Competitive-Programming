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
	//fast;
	int t;  scanf("%d", &t);
	while (t--){
		map<string, double>mp;
		mp["JD"] = 1;
		string s;
		double x,ans = 0;
		int c, n;   scanf("%d%d", &c, &n);
		while (c--){
			char s[15];
			scanf("%s", s);
			scanf("%lf", &x);
			mp[s] = x;
		}
		while (n--){
			scanf("%lf", &x);
			char s[15];
			scanf("%s", s);
			ans += (x*mp[s]);
		}
		cout << stpr(6) << ans << ed;
	}
}
