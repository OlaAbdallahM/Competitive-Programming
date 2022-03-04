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
lli cnt, sum;
int main()
{
	fast();
	lli n; cin >> n;
	string ss[] = { "", "one", "two", "three"};
	while (n--)
	{
		string s; cin >> s;
		if (s.size() == 3 && (s.find('o') != string::npos && s.find('n') != string::npos && s.find('e') != string::npos) 
			|| (s.find('o') != string::npos && s.find('n') != string::npos) || (s.find('n') != string::npos && s.find('e') != string::npos)
			|| (s.find('o') != string::npos && s.find('e') != string::npos)) cout << 1 << endl;
		else if (s.size() == 3 && (s.find('t') != string::npos && s.find('w') != string::npos && s.find('o') != string::npos)
			|| (s.find('t') != string::npos && s.find('w') != string::npos) ||
			(s.find('w') != string::npos && s.find('o') != string::npos) || (s.find('t') != string::npos && s.find('o') != string::npos)) cout << 2 << endl;
		else cout << 3 << endl;
	}
}