#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah Almost3aan
Make it happens :) */
#include<bits/stdc++.h>


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
const ll mod = 1e9 + 7, N = 1e5 + 5, M = 5005;

ll nCr[35][35];

int main(){
	fast;
	int t = 0;
	nCr[0][0] = 1;
	for (int i = 1; i <= 25; i++) {
		nCr[i][0] = 1;
		for (int j = 1; j <= i; j++) 
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
	}

	int n; 
	while (cin >> n){
		if (t)cout << ed;
		t = 1;
		cout << nCr[n << 1][n] / (n + 1)<<ed;
	}
}