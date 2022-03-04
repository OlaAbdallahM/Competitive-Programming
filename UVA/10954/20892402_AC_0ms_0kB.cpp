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
bool vis[SZ];
lli len, sp[SZ];
lli cnt, sum,mn=INF,ans,mxx=0, mx;
vector<lli>primes;
lli frq[3];
int main()
{
	fast();
	lli q; //cin >> q;
		q = 1;
		lli n;
		while (cin>>n)
		{
			if (n == 0) return 0;
			vector<lli>a(n);
			priority_queue<lli>pq;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
				a[i] *= -1;
				pq.push(a[i]);
			}
			ans = 0;
			while (pq.size()>1)
			{
				lli x = pq.top();
				pq.pop();
				x += pq.top();
				pq.pop();
				pq.push(x);
				ans += (-1 * x);
			}
			cout << ans << endl;
		}
}	

