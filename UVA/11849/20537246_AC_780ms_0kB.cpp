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
lli cnt, sum, ans;
int main()
{fast();lli q;   //  cin >> q;
	                  q = 1;
     while (q--)
	{
		 lli n, m,x; 
		 while (cin >> n >> m)
		 {
			 if (!n&&!m)return 0;
			 set<lli>st;
		 while (n--)
		 {
			 cin >> x;
			 st.insert(x);
		 }
		 while (m--)
		 {
			 cin >> x;
			 if (st.count(x))ans++;
	     }
			 cout << ans << endl;
			 ans = 0;
		 }
	}
}