//               Allah_Almost3aan        *{فَصَبْرٌ جَمِيلٌ وَاللَّهُ الْمُسْتَعَانُ }*
//                  *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define _CRT_SECURE_NO_WARNINGS
#define endl "\n"
#define mod 100000007 //1e9+7
#define INF 1000000000 //1e9
#define SZ 2000001
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
	lli j;
	string s;
	while (cin >> s)
	{
		string cur;
		bool ola = true;
		deque<string>dq;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '[') {
				if (ola)dq.push_back(cur);
				else dq.push_front(cur);
				ola = false;
				cur.clear();
			}
			else if (s[i] == ']') {
				if (ola)dq.push_back(cur);
				else dq.push_front(cur);
				ola = true;
				cur.clear();

			}
			else cur += s[i];
		}
		if (ola)dq.push_back(cur);
		else dq.push_front(cur);
		while (dq.size())
		{
			cout << dq.front();
			dq.pop_front();
		}
		cout << endl;
	}
}