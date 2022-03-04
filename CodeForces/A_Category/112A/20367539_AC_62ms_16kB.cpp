//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lli = long long int;
#define mod 10000000000000000007 //1e9+7
#define INF 1000000000 //1e9
#define SZ 200001
void fast() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif 
}
lli ans, sum,freq,cnt;
int main()
{
	fast();
	string s, x; cin >> s >> x;
	for (int i = 0; i < s.size();i++)
	if (s[i] >= 'A'&&s[i] <= 'Z')
		s[i] += 32;
	for (int i = 0; i < x.size(); i++)
	if (x[i] >= 'A'&&x[i] <= 'Z')
		x[i] += 32;
	if (s>x)cout << 1 << endl;
	else if (s == x) cout << 0 << endl;
	else cout << -1 << endl;
}