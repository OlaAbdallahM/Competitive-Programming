#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
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
string ys = "YES", no = "NO"; const int N = 4 * (1 << 17), M = 1 << 10;
const ll mod = 1e9 + 7;



int n, x;
ll dp[25][150];

ll gcd(ll n, ll m) {
	return !m ? n : gcd(m, n % m);
}

ll nEvent(int n, int score) {
	if (n == 0) {
		if (score >= x)
			return 1;
		else
			return 0;
	}
	if (dp[n][score] != -1)
		return dp[n][score];

	ll ans = 0;
	for (int i = 1; i <= 6; i++) {
		ans += nEvent(n - 1, score + i);
	}

	return dp[n][score] = ans;
}

int main() {
	ll event, space, esgcd;

	while (scanf("%d %d", &n, &x), n || x) {
	reset(dp,-1);
		space = pow(6.0, n);
		event = nEvent(n, 0);

		esgcd = gcd(space, event);
		event = event / esgcd;
		space = space / esgcd;

		if (event == 0)
			printf("0\n");
		else if (space == 1)
			printf("%lld\n", event);
		else
			printf("%lld/%lld\n", event, space);
	}

	return 0;
}