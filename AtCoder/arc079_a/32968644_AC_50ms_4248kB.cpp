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
string ys = "YES", no = "NO"; const int N = 1e5 + 5, M = (1 << 10) + 10;
const ll mod = 1e9 + 7;


int pow10[N + 9], cum[N + 9];
string s;

int main(){    
	fast
		int n, m;cin >> n >> m;
             vi v1, vn;
	 while(m--) {
		int a, b;cin >> a >> b;
		if (a == 1)v1.push_back(b);
		if (b == n)vn.push_back(a);
	}
	bool ans = 0;
	sort(all(v1));sort(all(vn));
	for (auto i : v1) {
		auto it = lower_bound(vn.begin(), vn.end(), i);
		if (it != vn.end() && i ==*it)
			ans = 1;
	}
	cout<<(ans?"POSSIBLE\n": "IMPOSSIBLE\n");
}