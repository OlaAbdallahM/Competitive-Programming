
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
lli ans, sum,freq;
int main()
{
	fast();
	string s; getline(cin, s);
	for (int i = 0; i<s.size() - 1; i++)
	{
		if (s[i] == ' '&&s[i + 1] == ' '){ s.erase(i, 1); i--; }
		if ((s[i] == ' '&&s[i + 1] == ',') || (s[i] == ' '&&s[i + 1] == '?') || (s[i] == ' '&&s[i + 1] == '!') || (s[i] == ' '&&s[i + 1] == '.'))
		{ s.erase(i, 1); }
		if ((s[i] == ','&&s[i + 1] != ' ') || (s[i] == '!'&&s[i + 1] != ' ') || (s[i] == '?'&&s[i + 1] != ' ') || (s[i] == '.'&&s[i + 1] != ' '))
		{ s.insert(i + 1, " "); }
	}
	cout << s << endl;
}