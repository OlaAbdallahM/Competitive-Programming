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
#ifndef ONLINE_JUDGE //freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif 
}
map<string, lli>mp;
lli k = 2;
string s;
void sum(string cur)
{
	//if (cur == s)return;
//	if (cur.size() > s.size())return;
		if (cur[cur.size() - 1] == 'z'){
			if (cur == "z")cur = "ab";
			else if (cur == "yz") cur = "abc";
			else if (cur == "xyz")cur = "abcd";
			else if (cur == "wxyz") cur = "abcde";
			else if (cur == "vwxyz")return;
			else{
				char temp = cur[cur.size()-2];
				cur[cur.size() - 2] =temp+ 1;
				cur[cur.size() - 1] = temp + 2;
			}
		}
		else {
			cur[cur.size() - 1]++;
		}
		mp[cur] = k++;
		sum(cur);
}
lli cnt, ans,mx;
lli frq[26];
int main()
{
	fast();
	lli q;  //cin >> q;
	q = 1;
	while (q--)
	{
		lli n;
		while (cin >> n)
		{
			if (n == 0)return 0;
			ans = 0, mx = 0;
			map<vector<lli>, lli > mp;
			while (n--){
				vector<lli> a(5);
				for (int i = 0; i < 5; i++)cin >> a[i];
				sort(a.begin(), a.end());
				mp[a]++;
				if (mp[a]>mx)
				{
					mx = mp[a];
					ans = mp[a];
				}
				else if (mp[a]==mx)
				{
					ans += mp[a];
				}

			}
			cout << ans << endl;
		}

	}
}
