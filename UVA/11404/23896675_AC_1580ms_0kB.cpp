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
string s,tmp; 
vector<ll>v;
pair<int,string>mem[(1 << 10)][(1 << 10)];
pair<int,string>sol(pair<int,string>a, pair<int,string>b)
{
	if (a.ff > b.ff) return a;
	if (a.ff < b.ff) return b;
	if (a.ss < b.ss) return a;
	return b;
}
pair<int,string>build(ll i, ll j)
{
	if (i == j)
		return{ 1, tmp = s[i] };
	if (i > j) return{ 0, "" };
	pair<int, string>&rt = mem[i][j];
	if (~rt.ff)return rt;
	if (s[i] == s[j])
	{
		rt.ff = 2 + build(i + 1, j - 1).ff;
		rt.ss = s[i] + build(i + 1, j - 1).ss + s[j];
		return rt;
	}
	return rt = sol(build(i, j - 1), build(i + 1, j));
}
int main(){
	fast();
	while (cin >> s)
	{
		for (int i = 0; i<sz(s); i++)
			for (int j = 0; j<sz(s); j++)
				mem[i][j].first = -1;
		cout << build(0, sz(s) - 1).ss << ed;;
	}
}