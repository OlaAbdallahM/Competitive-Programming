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
#define EPS 1e-12
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
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e8 + 7, N = 2e5 + 5, M = 2001;

#define maxN 1000001
int ans[maxN];
bool isPrime[maxN];
vector<int> prime;

void Sieve() {
	memset(isPrime, true, maxN);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2, lm = (int)sqrt(maxN); i <= lm; i++)
	if (isPrime[i]) {
		for (int j = i*i; j <= maxN; j += i)
			isPrime[j] = false;
		prime.push_back(i);
	}
	for (int i = prime.back() + 1; i <= maxN; i++)
	if (isPrime[i]) prime.push_back(i);
}

void PreCal() {
	Sieve();
	ans[1] = 0;
	for (int i = 2; i<maxN; i++) {
		ans[i] = ans[i - 1];
		int n = i, j = 0;
		while (!isPrime[n]) {
			if (n%prime[j] == 0) {
				ans[i]++;
				n /= prime[j];
			}
			else j++;
		}
		if (isPrime[n]) ans[i]++;
	}
}

main() {
	int n;
	PreCal();
	while (scanf("%d", &n) != EOF)
		printf("%d\n", ans[n]);
}