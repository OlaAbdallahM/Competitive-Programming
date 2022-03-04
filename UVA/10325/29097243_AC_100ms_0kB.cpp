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
const long double rad = acos(-1) / 180, dgr = 180 / acos(-1);
const int mod = 1e9 + 7, N = 2e5 + 5;

ll gcd(ll a, ll b)
{
	return (!b ? a : gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)*b);
}

ll n, m;
vi ar;
ll div()
{

	ll rt = 0;
	for (int i = 1; i < 1 << m; i++)
	{
		ll lc = 1;
		int cnt = 0;
		for (int j = 0; j < m; j++)
		if (i& (1 << j))
		{
			lc = lcm(lc, ar[j]);
			cnt++;
		}
		if (cnt & 1)
			rt += (n / lc);
		else  rt -= (n / lc);
	}
	return rt;
}

int main()
{
	fast;
	while (cin >> n >> m){
		ar.resize(m);
		for (auto&i : ar)cin >> i;
		cout <<n- div() << ed;
	}

}