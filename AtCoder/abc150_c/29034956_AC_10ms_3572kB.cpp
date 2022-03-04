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
const ll OO = 1e18;
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;
const auto EPS = 1e-9;

ll fact[10];
int n;
ll permtoindx(vi perm){
	ll idx = 0;
	for (int i = 0; i < n; i++){
		idx += fact[n - i - 1] * perm[i];
		for (int j = i + 1; j < n; j++)
			perm[j] -= perm[j]>perm[i];
	}
	return idx;
}
int main()
{
	fast;
	fact[1] = 1;
	for (ll i = 2; i <= 10; i++)
		fact[i] = i*fact[i - 1];
	 cin >> n;
	vi perm, a(n), b(n);
	for (auto&i : a) cin >> i;
	for (auto&i : b) cin >> i;
	
	cout << abs(permtoindx(a)- permtoindx(b)) << ed;
}


