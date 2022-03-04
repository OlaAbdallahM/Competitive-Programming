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
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
string s; 
ll mem[66][66];
ll dp(int i, int j)
{
	if (i == j) return 1;
	if (j - i == 1) return 2+(s[i]==s[j]);
	ll&rt = mem[i][j];
	if (~rt) return rt;
	rt = 0;
	if (s[i] == s[j]) rt += 1 + dp(i + 1, j - 1);
	rt += dp(i + 1, j);
	rt += dp(i, j - 1);
	rt -= dp(i + 1, j - 1);
	return rt;
}
int main(){ 
	fast();
	int t; cin >> t;
	while (t--)
	{
		memset(mem, -1, sizeof mem);
		cin >> s;
		cout << dp(0,sz(s)-1) << ed;
	}
	
}
