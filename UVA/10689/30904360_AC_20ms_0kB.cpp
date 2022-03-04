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

struct M {
	int v[2][2];
} I = { 1, 0, 0, 1 }, o = { 0, 0, 0, 0 }, A = { 1, 1, 1, 0 };
void mult(M &a, M &b, int m) {
	M t = o;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				t.v[i][j] += a.v[i][k] * b.v[k][j];
				t.v[i][j] %= m;
			}
		}
	}
	a = t;
}
M calc(int n, int m) {
	M x = I, y = A;
	while (n) {
		if (n & 1) mult(x, y, m);
		mult(y, y, m);
		n /= 2;
	}
	return x;
}
int main() {
	int n, m, a, b, t;
	cin >> t;
	while (t--) {
		cin>>a>>b>>n>>m;
		m = (int)pow(10, m);
		M res = calc(n, m);
		int ans = res.v[1][0] * b + res.v[1][1] * a;
		cout<<ans%m<<ed;
	}
	return 0;
}