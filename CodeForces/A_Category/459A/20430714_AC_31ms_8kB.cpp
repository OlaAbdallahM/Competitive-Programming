
//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define _CRT_SECURE_NO_WARNINGS
#define endl "\n"
#define mod 10000000000000000007 //1e9+7
#define INF 1000000000 //1e9
#define SZ 1000001
void fast() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif 
}
lli ans,cnt,sum;

int main()
{
	fast();
	lli x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2)return cout << x1 + abs(y2 - y1) << ' ' << y1 << ' ' << x2 + abs(y2 - y1) << ' ' << y2, 0;
	if (y1 == y2)return cout << x1 << ' ' << y1 + abs(x2 - x1) << ' ' << x2 << ' ' << y2 + abs(x2 - x1), 0;
	if (abs(x2 - x1) == abs(y2 - y1))return cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1, 0;
	cout << -1;
}