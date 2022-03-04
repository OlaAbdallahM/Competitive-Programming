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
const int mod = 1e9 + 7, N = 1e5 + 5, M = 50000;

/*The meaning of the problem: the optimal matrix chain multiplication,
give the size of n matrices, find the calculation order, and let the calculation amount be the smallest.

Memory search, the state transition formula 
is dp(begin, end) = { dp(begin, k) + dp(k + 1, end) + x[begin] * y[k] * y[end] | begin <= k <= end }*/


const int MAXN = 15;
const int INF = 0x7fffffff;
int x[MAXN], y[MAXN];
int d[MAXN][MAXN], r[MAXN][MAXN];

int dp(int a, int b) {
	if (d[a][b] != -1) return d[a][b];
	r[a][b] = a;
	if (a == b) return d[a][b] = 0;
	d[a][b] = INF;
	int t;
	for (int i = a; i < b; i++) {
		t = dp(a, i) + dp(i + 1, b) + x[a] * y[i] * y[b];
		if (t < d[a][b]) {
			d[a][b] = t;
			r[a][b] = i;
		}
	}
	return d[a][b];
}

void print(int a, int b) {
	if (a > b) return;
	if (a == b)
		printf("A%d", a + 1);
	else {
		printf("(");
		print(a, r[a][b]);
		printf(" x ");
		print(r[a][b] + 1, b);
		printf(")");
	}
}

int main() {
	int n, cas = 0;
	while (scanf("%d", &n) && n) {
		memset(d, -1, sizeof(d));
		for (int i = 0; i < n; i++)
			scanf("%d%d", &x[i], &y[i]);
		// dp
		dp(0, n - 1);
		printf("Case %d: ", ++cas);
		print(0, n - 1);
		puts("");
	}
	return 0;
}