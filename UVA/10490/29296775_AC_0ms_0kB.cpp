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
const int mod = 1e18, N = 1e5, M = 50000;


ll fast_power(ll base, ll power)
{
	ll ans = 1;
	while (power > 0){
		if (power & 1) ans = (ans*base);
		base = (base*base);
		power >>= 1;
	}
	return ans;
}

bool isprime(ll n)
{
	if (n == 0 || n == 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	for (ll i = 5; i*i <= n; i += 6)
	if (n%i == 0 || n % (i + 2) == 0) return 0;
	return 1;
}

int main()
{
	fast;
	ll n, nn;
	while (cin >> n)
	{
		if (n == 0) return 0;
		if (isprime(n)){
			if (isprime((fast_power(2ll, n) - 1)))
				cout << "Perfect: " << fast_power(2ll, n - 1)*(fast_power(2ll, n) - 1) << "!\n";
            else 
				cout << "Given number is prime. But, NO perfect number is available.\n";
		}else
			cout << "Given number is NOT prime! NO perfect number is available.\n";
	}
}