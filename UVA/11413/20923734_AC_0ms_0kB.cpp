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
vector<lli>a(1000);
bool ok(vector<lli>a, lli n, lli m, lli md)
{
		lli i = 0, cur = md;
		while (i<n&&m>0)
		{
			if (a[i] <= cur)
			{
				cur -= a[i];
				i++;
			}
			else
			{
				cur = md;
				m--;
			}
		}
		return i == n;
}
int main()
{
	fast();
	lli q; //cin >> q;
		q = 1;
		lli n, m;
		while (cin>>n)
		{
			if (n == 0)return 0;
			 cin >>m;
			 for (int i = 0; i < n; ++i)
			 {
				 cin >> a[i];
				 sum += a[i];
			 }
			int ans = -1, l = 0, r = sum;
			while (l <= r)
			{
				int mid = l + r>>1;
				if (ok(a, n, m, mid))
				{
					ans = mid;
					r = mid-1;
				}
				else
					l = mid + 1;
			}
			cout << ans << endl;
		}
}	

