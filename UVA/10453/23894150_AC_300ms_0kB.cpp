#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan 
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using  ll = long long;
const ll OO = 1e18;
#define MOD 1e9+7
#define fnt 0x3f3f3f3f
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define stpr(n) fixed<<setprecision(n)
#define clr(mem) memset(mem, -1, sizeof mem)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
bool md; 
string s; 
vector<ll>v;
ll mem[(1 << 10)][(1 << 10)];
int sol(ll i, ll j)
{
	if (i >= j) return 0;
	ll &rt = mem[i][j];
	if (~rt) return rt;
	if (s[i] == s[j])rt = sol(i + 1, j - 1);
	else rt = 1 + min(sol(i + 1, j), sol(i, j - 1));
	return rt;
}
void sol2(ll i, ll j)
{
	if (i == j)
	{
		v.push_back(i);
		md = 1;
	}
	if (i >= j) return;
	if (s[i] == s[j])
	{
		v.push_back(i);
		sol2(i + 1, j - 1);
	}
	else if (sol(i, j) == 1 + sol(i + 1, j))
	{
		v.push_back(i);
		sol2(i + 1, j);
	}
	else
	{
		v.push_back(j);
		sol2(i, j - 1);
	}
}
int main(){
	fast();
	while (cin >> s)
	{
		clr(mem);
		v.clear();
		md = 0;
		ll ans = sol(0, sz(s) - 1);
		sol2(0, sz(s) - 1);
		cout << ans << " ";
		for (auto i : v) cout << s[i];
		for (int i = sz(v) - md - 1; i >= 0; i--)
			cout << s[v[i]];
		cout << ed;
	}
}