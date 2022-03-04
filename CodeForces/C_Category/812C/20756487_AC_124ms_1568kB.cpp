#define _CRT_SECURE_NO_WARNINGS
//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define endl "\n"
#define mod 100000007 //1e9+7
#define INF 1000000000 //1e9
#define SZ 100001
void fast() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif 
}
lli ans, sum, mx;
int main()
{
	fast();
	lli q;   //cin >> q;
	q = 1;
	while (q--)
	{
		lli n, s; cin >> n >> s;
		vector<lli>a(n);
		for (int i = 0; i<n; i++)cin >> a[i];
		lli l = 0, r = n, cost;
		while (l <= r)
		{
			lli k = l + r>>1;
			vector<lli>b(n);
			for (int i = 0; i < n; i++)
				b[i] = a[i] + k*(i + 1);
			sort(b.begin(), b.end());
			lli sum = 0;
			for (int i = 0; i < k; i++)sum += b[i];
			if (sum <= s){
				l = k + 1; cost = sum;
			}
			else r = k - 1;
		}
		cout << l - 1 << " " << cost << endl;
	}
}