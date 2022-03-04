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
lli cnt, sum, ans,mx;
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
bool ok[SZ];
lli n;
lli dist(lli a,lli b,lli c, lli d)
{
	return (a - c)*(a - c) + (b - d)*(b - d);
}
int main()
{
	fast();
	
	lli q; //cin >> q;
	        q = 1;
	while (q--)
	{
		map<pair<lli, lli>, bool>bo;
		int  x1, y1, x2, y2, n, cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		while (n--)
		{
			int r, rr;
			pair<lli, lli>m;
			cin >> m.first >> m.second >> r;
			rr = r*r;
			for (int i = y1; i <= y2; i++)
			{

				if (dist(m.first, m.second, x1, i) <= rr)bo[{x1, i}] = true;
				if (dist(m.first, m.second, x2, i) <= rr)bo[{x2, i}] = true;
			}
			for (int i = x1; i <= x2; i++)
			{

				if (dist(m.first, m.second, i, y1) <= rr)bo[{i, y1}] = true;
				if (dist(m.first, m.second, i, y2) <= rr)bo[{i, y2}] = true;
			}
		}
		if (!bo[{x1, y1}])cnt++; if (!bo[{x1, y2}])cnt++;

		if (!bo[{x2, y1}])cnt++; if (!bo[{x2, y2}])cnt++;
		for (int i = y1 + 1; i < y2; i++) {
			if (!bo[{x1, i}])cnt++;
			if (!bo[{x2, i}])cnt++;
		}
		for (int i = x1 + 1; i < x2; i++) {
			if (!bo[{i, y1}])cnt++;
			if (!bo[{i, y2}])cnt++;
		}
		cout << cnt<<endl;
	}
}

