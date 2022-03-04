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
int mem[1005][1005];
int sol(int i, int j)
{
	int &rt = mem[i][j];
	if (rt != 2e9)return rt;
	if (j<= i) return rt = 0;
	if (s[i] == s[j])
		return rt = sol(i + 1, j - 1);
	else 
		return rt = 1 + min({ sol(i + 1, j), sol(i, j - 1), sol(i + 1, j - 1) });
}
int main(){
	fast();
	int t; cin >> t;
	for (int k = 1; k <= t;k++)
	{
		cin >> s;
		for (int i = 0; i < sz(s);i++)
		for (int j = 0; j < sz(s); j++)
			mem[i][j] = 2e9;
		cout << "Case " << k << ": " << sol(0, sz(s) - 1) << ed;
	}
}
