#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan 
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using  ll = long long;
const ll OO = 1e18;
#define MOD 1e9+7
#define fnt 0x3f3f3f3f
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
const int N = 1e4 + 4;
int v[N], lft[N], rit[N], mem[N];
int main(){
	fast();
	int n; 
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> v[i];
		// assigne the LDS from left to each index 
		memset(lft, -1, sizeof lft);
		memset(mem, -1, sizeof mem);
		int idx, len = 0;
		for (int i = 0; i < n; i++)
		{
			idx = lower_bound(mem, mem + len, v[i]) - mem;
			mem[idx] = v[i];
			if (idx == len)len++;
			lft[i] = idx + 1;
		}
		// assigne the LIS from right to each index 
		reverse(v, v + n);
		memset(rit, -1, sizeof rit);
		memset(mem, -1, sizeof mem);
		 idx, len = 0;
		for (int i = 0; i < n; i++)
		{
			idx = lower_bound(mem, mem + len, v[i]) - mem;
			mem[idx] = v[i];
			if (idx == len)len++;
			rit[i] = idx + 1;
		}
		reverse(rit, rit + n);

		int mx = 0;
		for (int i = 0; i < n; i++)
			mx = max(mx, min(lft[i], rit[i]));
		cout << 2 * mx - 1 << ed;
	}
}
