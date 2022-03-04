#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll =  long long;
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1<<10;
const ll mod = 1e9 + 7;

int gcd(int a, int b){
	return(!b ? a : gcd(b,a%b));
}

ll Gcd(ll a, ll b)
{
	for (ll t = a % b; t; a = b, b = t, t = a % b); return b;
}

ll extended_euclid(ll a, ll b,ll d, ll &x, ll &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	ll g= extended_euclid(b, a%b,d, y, x);
	y -= (a / b)*x;
	return g;
}
bool np[1000001];
vector <int> prime;
int prime_size;


void sieve()
{
	prime.push_back(2);
	np[0] = np[1] = true;
	for (ll i = 4; i <= 1000000; i += 2) np[i] = true;
	for (ll i = 3; i <= 1000000; i += 2)
	{
		if (!np[i])
		{
			prime.push_back(i);
			for (ll j = i*i; j <= 1000000; j += (i << 1)) np[j] = true;
		}
	}
	prime_size = prime.size();
}

ll solve(ll n){
	ll phi = n;
	for (int i = 0; i<prime_size && prime[i]*prime[i]<=n; i++)
	{
		if (!(n%prime[i]))
		{
			while (!(n%prime[i])) n/=prime[i];
			phi -= (phi/prime[i]);
		}
	}
	if (n>1) phi-=(phi/n);
	return phi;
}

int main()
{
	fast;
	sieve();
	ll n; while (cin >> n&&n){
		cout << solve(n) << ed;
	}
}