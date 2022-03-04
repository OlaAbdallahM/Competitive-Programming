#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan 
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using  ll = long long;
const ll OO = 1e18;
const int N = 2 * 1e5 + 5;
#define MOD 1e9+7
#define fnt 0x3f3f3f3f
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dj[8] = { 0, -1, 0, 1, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
ll  ncr(int n, int r)
{
	if (r > n - r)r = n - r;
	ll  ans = 1, j = 2;
	for (int i = n - r + 1; i <= n; i++)
	{
		ans *= i;
		while (!(ans%j) && j <= r)
		{
			ans /= j; j++;
		}
	}
	return ans;
}
int main(){
	fast();
	int n, m;
	while (cin >> n >> m)
	{
		if (!n&&!m)return 0;
		cout << n << " things taken " << m << " at a time is " << ncr(n, m) << " exactly." << ed;
	}
}