#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18, oo = 1e12 + 21;
#define ed '\n'
#define EPS 1e-10
#define PI acos(-1.0)
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
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, rad = 180 / acos(-1);
//const ll mod = 1e9 + 7, N = 1e5 + 5, M = 5005;

int main(){
	fast;
	int t; cin >> t;
	while (t--){
		int a, b, n, m; cin >> a >> b >> n >> m;
		m--;
		vi  rep = { 60, 300, 1500, 15000 }, mo = { 10, 100, 1000, 10000 };
		int mod = mo[m], len = rep[m];
		vi seq(len); seq[0] = a%mod, seq[1] = b%mod;
		for (int i = 2; i < len; i++)seq[i] = (seq[i - 1] + seq[i - 2]) % mod;
		cout << seq[n%len] << ed;
	}
}