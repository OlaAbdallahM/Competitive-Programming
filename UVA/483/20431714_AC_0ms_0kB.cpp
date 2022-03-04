
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
lli cnt,sum;

int main()
{
	fast();
	string s,ans,cur,remn;
	while (getline(cin, s))
	{
		s += ' '; ans.clear();
		while (s.size() > 1)
		{
			cur = s.substr(0, s.find(' '));
			cur = string(cur.rbegin(), cur.rend());
			ans=(ans+' '+ cur);
			s = s.substr(s.find(' ') + 1, s.size());
		}
		ans.erase(0, 1);
		cout << ans << endl;
	}
}