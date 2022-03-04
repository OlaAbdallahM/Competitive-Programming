#define _CRT_SECURE_NO_WARNINGS
//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
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
lli cnt, sum, ans;
lli frq[26];
int main()
{
	fast();
	lli q;   //scanf("%lld", &q);
	 	q = 1;
	
		while (q--)
		{
			lli n; scanf("%lld", &n);
			vector<lli>a(n);
			for (int i = 0; i < n; i++)scanf("%lld", &a[i]);
			sort(a.begin(), a.end());
			for (int i = 0, j = n - 1; i < n / 2; i++, j--)
				cout << a[i] << ' ' << a[j] << ' ';
			if (n & 1) printf("%lld", a[n / 2]);
		}
}
