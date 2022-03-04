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
int getBit(int num, int idx) {
	return ((num >> idx) & 1) == 1;		// 110100, idx = 4  -->  110 & 1 = 0
}
int setBit(int num, int idx,int value) {
	return(value) ? num | (1 << idx) : num & ~(1 << idx);
}
int flipBit(int num, int idx) {
	return num ^ (1 << idx);
}
int mem[1 << 12];
int best(int mask)
{
	int &rt = mem[mask];
	if (~rt) return mem[mask];
	rt = 0;
	for (int i = 0; i < 10; i++)
	{
		if (getBit(mask, i) && getBit(mask, i + 1) && !getBit(mask, i + 2))
		{
			int msk = mask;
			msk = setBit(msk, i, 0);
			msk = setBit(msk, i+1, 0);
			msk = setBit(msk, i+2, 1);
			rt = max(rt, 1 + best(msk));
		}
		if (!getBit(mask, i) && getBit(mask, i + 1) && getBit(mask, i + 2))
		{
			int msk = mask;
			msk = setBit(msk, i, 1);
			msk = setBit(msk, i + 1, 0);
			msk = setBit(msk, i + 2, 0);
			rt = max(rt, 1 + best(msk));
		}
	}
	return rt;
}
int main(){                  
	fast();
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int msk = 0, cnt = 0;
		for (int i = 0;i<sz(s);i++)
		{
			if (s[i] == 'o')
			{
				msk = setBit(msk, i, 1);
				cnt++;
			}
		}
		memset(mem, -1, sizeof mem);
		cout << cnt - best(msk) << ed;
	}
}
