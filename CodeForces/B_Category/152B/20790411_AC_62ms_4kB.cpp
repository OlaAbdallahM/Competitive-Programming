#define _CRT_SECURE_NO_WARNINGS
//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
using namespace std;
using lli = long long ;
#define endl "\n"
#define mod 100000007 //1e9+7
#define INF 1000000000 //1e9
#define SZ 2000001
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
void fast() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif 
}
long long  ncr(int n, int r)
{
	if (r > n - r)r = n - r; long long  ans = 1;
	lli j = 2;
	for (int i = n - r + 1; i <= n; i++){
		ans *= i;
		while (!(ans%j) && j <= r){
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
}
lli cnt,ans,mx;
lli pow_md(lli a,lli n,lli md)
{
	lli ans = 1;

	for (; n; n >>= 1)
	{
		if (n & 1)
			ans = (ans * 1ll * a) % md;

		a = (a * 1ll * a) % md;
	}

	return ans;
}
int main()
{
	fast();
	
	lli q; //cin >> q;
	        q = 1;
	while (q--)
	{
		lli p, n, m, x, y, k, a, b, sum = 0, k1, k2;
		cin >> n >> m >> x >> y >> k;
		while (k--)
		{
			cin >> a >> b;
			if (a>0)
				k1 = (n - x) / a;
			else if (a<0)
				k1 = (1 - x) / a;
			else
				k1 = m;
			if (b>0)
				k2 = (m - y) / b;
			else if (b<0)
				k2 = (1 - y) / b;
			else
				k2 = n;
			k1 = min(k1, k2);
			sum += k1;
			x += k1*a;
			y += k1*b;
		}
		cout << sum << endl;
	}
}

