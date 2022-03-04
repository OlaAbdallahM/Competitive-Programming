#define _CRT_SECURE_NO_WARNINGS
//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define endl "\n"
#define mod 100000007 //1e9+7
#define INF 1000000000 //1e9
#define SZ 2000001
void fast() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE 
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif 
}
lli cnt, sum, ans;
lli frq[26];
int main()
{
	fast();
	lli q;  cin >> q;
	//q = 1;
	while (q--)
	{
		string s1, s2, plus, minus, chang, temp;
		cin >> s1 >> s2;
		s1.erase(0, 1);    s1.erase(s1.size() - 1, 1); s1 += ',';
		s2.erase(0, 1);    s2.erase(s2.size() - 1, 1);    s2 += ',';
		map<string, string>mp1;
		map<string, string>mp2;
		while (s1.size() > 0)
		{
			temp = s1.substr(0, s1.find(','));
			s1 = s1.substr(s1.find(',') + 1);
			mp1[temp.substr(0, temp.find(':'))] = temp.substr(temp.find(':') + 1);
		}
		while (s2.size() > 0)
		{
			temp = s2.substr(0, s2.find(','));
			s2 = s2.substr(s2.find(',') + 1);
			mp2[temp.substr(0, temp.find(':'))] = temp.substr(temp.find(':') + 1);
		}
		for (auto it : mp1)
		{
			if (!mp2.count(it.first))
			{
				minus += "," + it.first;
			}
			else
			{
				if (mp2[it.first] != it.second)
					chang += "," + it.first;
			}
		}
		for (auto it : mp2)
		{
			if (!mp1.count(it.first))
			{
				plus += "," + it.first;
			}
		}
		if (plus.size()) plus.erase(0, 1), plus = '+' + plus;
		if (minus.size()) minus.erase(0, 1), minus = '-' + minus;
		if (chang.size()) chang.erase(0, 1), chang = '*' + chang;
		if (plus.size() <= 1 && minus.size() <= 1 && chang.size() <= 1)
			cout << "No changes" << endl;
		else
		{
			if (plus.size() > 1)cout << plus << endl;
			if (minus.size() > 1)cout << minus << endl;
			if (chang.size() > 1)cout << chang << endl;
		}
		cout << endl;
	}
}