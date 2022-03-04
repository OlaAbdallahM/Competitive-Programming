
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
	lli n; cin >> n;
	vector<lli>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1)
	{
		if (a[0] == 0)return cout << "UP", 0;
		if (a[0] == 15)return cout << "DOWN", 0;
		cout << -1;
	}
	else if (a[n - 1] == 15 )return cout << "DOWN", 0;
	else if (a[n - 1] == 0)return cout << "UP", 0;
	else if (a[0] == a[n-1])return cout << "DOWN", 0;
	else if (a[n - 1]>a[n - 2])cout << "UP";
	else cout << "DOWN";
}