
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
	string s, ss; getline(cin, s);
	while (s != "DONE")
	{
		ss.clear();
		for (int i = 0; i < s.size(); i++)
		{
			if (isalpha(s[i]))
			{
				if (s[i] >= 'A'&&s[i] <= 'Z')
					ss += char(s[i] + 32);
				else ss += s[i];
			}
		}
		string z = string(ss.rbegin(), ss.rend());
		cout << (ss == z ? "You won't be eaten!" : "Uh oh..") << endl;
		getline(cin, s);
	}
}