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
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e18, N = 2e5;

bool isPrime[N];
vector<int> primes;
void sieve() {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i < N; i += 2) isPrime[i] = false;
	for (ll i = 3; i * i < N; i++)
	if (isPrime[i])
	for (ll j = i * i; j < N; j += i + i)
		isPrime[j] = false;
	primes.push_back(2);
	for (int i = 3; i < N; i += 2)
	if (isPrime[i]) primes.push_back(i);
}

int main(){
	fast;
	sieve();
	vi prime;
	for (auto i : primes)if (isPrime[(i + 1) / 2])prime.push_back(i);
	//for (auto i : prime)cout << i << " ";
	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		cout << (upper_bound(all(prime), r)-prime.begin())-(lower_bound(all(prime), l) -prime.begin())<< ed;
	}
}