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
lli cnt, sum, ans;
lli frq[26];
int main()
{
	fast();
	lli q;   //scanf("%lld", &q);
	 	q = 1;
	
		while (q--)
		{ 
			lli n; 
			while (scanf("%lld",&n))
			{
				if (n == 0)
					break;
				lli a = 0, b = 0;
				bool turn = true;
				for (int i = 0; i < 32; i++)
				if (((1 << i) & n) != 0) {
					if (turn)
						a |= 1 << i;
					else
						b |= 1 << i;
					turn = !turn;
				}
				printf("%lld %lld\n", a,b); 
			}
		}
}
