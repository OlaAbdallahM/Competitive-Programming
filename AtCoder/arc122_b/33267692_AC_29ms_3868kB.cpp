#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using ll = long long;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
const ll OO = 0x3f3f3f3f3f3f3f3fLL;
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 2e5 + 5, M = (1 << 10) + 10;
const ll mod = 1e9 + 7;



int main() {
	fast;
	int n; cin >> n;
	vector<ll>v(n);
	ll all = 0;
	for (auto &i : v) cin >> i,all+=i;
	sort(all(v));
	long double ans=1e18,sum=0,val;
	
	for (int i = 0; i < n;i++){
		sum += v[i];
		val = all - sum - 1ll * (n - i - 1)*v[i];
		ans= min(ans,val+(long double)v[i]*n/2);
	}
	ans /= n;
	cout << stpr(20)<<ans<< ed;

}



