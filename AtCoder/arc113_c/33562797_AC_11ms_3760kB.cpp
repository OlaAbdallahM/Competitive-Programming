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
string ys = "YES", no = "NO"; const int N = 100, M = (1 << 10) + 10;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll  b){
	return(!b ? a : gcd(b, a%b));
}
ll lcm(ll n, ll m){
	return n / gcd(n, m)*m;
}

int frq[26];

int main(){
	fast;
	string s; cin >> s;
	int n = sz(s);
	ll ans = 0;
	for (int i = n - 1; i > 0; i--){
		if (s[i] == s[i - 1]){
			ans += (n - i - 1 - frq[s[i] - 'a']);
			for (int j = 0; j < 26; j++)frq[j] = 0;
			frq[s[i] - 'a'] = n - i - 1;
		}
		frq[s[i] - 'a']++;
	}
	cout << ans << ed;
}



