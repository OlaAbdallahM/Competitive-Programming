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
		lli n; cin >> n;
		while (n)
		{
			ans += (n & 1);
			n >>= 1;
		}
		cout << ans<<endl;
	}
}