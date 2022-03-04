#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define pb push_back
#define endl '\n';
#define salam  return 0
#define sz(s) int(s.size())
#define Ceil(x,y)  ((x+y-1)/y)
#define all(v) ((v).begin()),((v).end())
#define allr(v) ((v).rbegin()), ((v).rend()) 
#define mem(x,y) memset(x,y,sizeof(x))
#define fix(n)  fixed<<setprecision(n)
#define palindrom(s)  (s==string(s.rbegin(),s.rend()))
#define tras(s)  transform(s.begin(), s.end(), s.begin(), ::tolower)
#define I64 int 
typedef long long ll;
typedef unsigned long long ull;
typedef double dl;
typedef long double ld;
const ll mod = ll(1e9 + 7);
const double PI = acos(-1.0);
const int N = (int)1e6 * 2, OO = 0x3f3f3f3f;
using namespace std;
void Selim()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
ll n, q, arrow,sum;
vector<ll>v;
ll bin_search(){
	ll lo = 1, hi = n, md, ans = 0;
	while (lo <= hi){
		md = (lo + hi) >> 1;
		if (v[md] - sum <= arrow){
			ans = md;
			lo = md + 1;
		}
		else{
			hi = md - 1;
		}
	}
	return ans;
}
void solve(){
	cin >> n >> q;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++){
		v[i] += v[i - 1];
	}
	sum = 0;
	while (q--){
		cin >> arrow;
		ll idx = 0;
		idx = bin_search();
		cout << (n - idx == 0 ? n : n - idx) << endl;
		sum += arrow;
		if (sum >= v[n])sum = 0;
	}
}
int main()
{
	Selim();

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	salam;
}