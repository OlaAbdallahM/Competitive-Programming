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
	string s; cin >> s ;
	set<char>ss(s.begin(), s.end());
	cout << (ss.size() & 1 ? "IGNORE HIM!":"CHAT WITH HER!") << endl;
}