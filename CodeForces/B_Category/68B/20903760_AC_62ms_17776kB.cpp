#define _CRT_SECURE_NO_WARNINGS
//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define endl "\n"
#define mod 1e9+7
#define INF 1e9
#define SZ 2000001
void fast() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif 
}
long long  ncr(int n, int r)
{
	if (r > n - r) 
		r = n - r;
	long long  ans = 1;
	lli j = 2;
	for (int i = n - r + 1; i <= n; i++)
	{
		ans *= i;
		while (!(ans%j) && j <= r)
		{
			ans /= j; j++;
		}
	}
	return ans;
}
lli gcd(lli a, lli  b)
{
	if (b == 0)return a;
	else
		return gcd(b, a%b);
}
lli lcm(lli n, lli m)
{
	return n*m / gcd(n, m);
}
bool isprime(lli n)
{
	if (n == 0 || n == 1)return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	for (int i = 5; i <= sqrt(n); i += 6) if (n%i == 0 || n % (i + 2) == 0)
		return 0;
	return 1;
	//for (int i = 2; i < 1e6; i++)
	//if (isprime(i))
	//	primes.push_back(i);
}
bool vis[SZ];
lli len, sp[SZ];
lli cnt, sum,mn=INF,ans,mxx=0, mx;
vector<lli>primes;
lli frq[3];
bool ok(int n,vector<lli>a, double k, double md)
{
	double	s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] - md >0)
		{
			double x = a[i] - md;
			x -= (x * k / 100);
			s1 += x;
		}
		else if (a[i] - md < 0)
		{
			s2 += md - a[i];
		}
	}
	if (s1 - s2 < 1e-6)return 1;
	else return 0;
}
int main()
{
	fast();
	lli q; //cin >> q;
		q = 1;
		while (q--)
		{
			lli n;
			double k; cin >> n >> k;
			vector<lli>a(n);
			for (int i = 0; i < n; i++) cin >> a[i];
			sort(a.begin(), a.end());
			double l = a[0], r = a[n-1];
			for (int i = 1; i <= 100; i++)
			{
				double md =( l + r)/2;
				if (ok(n, a, k,md))
					r= md;
				else l = md;
			}
			cout<<fixed<<setprecision(9)<<r<< endl;
		}
}	

