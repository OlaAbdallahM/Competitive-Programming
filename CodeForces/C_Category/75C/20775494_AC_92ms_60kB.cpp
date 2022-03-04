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
lli frq[26];
int main()
{
	fast();
	lli a, b; cin >> a >> b;
	vector<lli>v;
	if (a < b) swap(a, b);
	lli g = gcd(a, b); 
	for (int i = 1; i*i <= g; i++)
	if (!(g%i)) v.push_back(i), v.push_back(g / i);
	lli q;  cin >> q;
	         //q = 1;
	//for (int i = 0; i < v.size(); i++)cout << v[i] << " ";
	while (q--)
	{
		mx = 0;
		lli l, r; cin >> l >> r;
		for (int i = 0; i < v.size(); i++)
		if (v[i] >= l&&v[i] <= r) mx = max(mx, v[i]);
		if (mx)
			cout << mx << endl;
		else
			cout << -1<<endl;
	}
}

