#define _CRT_SECURE_NO_WARNINGS
// to be or not to be !!! Allah_Almost3aan 
//  Make it happen :)
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define stpr(n)fixed<<setprecision(n)
#define reset(mem,val)memset(mem,val,sizeof mem)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
const int N = 1e3 + 3;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int getBit(int num, int idx) {
	return ((num>>idx)&1==1);
}
int setBit(int num, int idx,int val) {
	return (val?(num|(1<<idx)):(num&~(1<<idx)));
}
int flipBit(int num, int idx) {
	return num ^ (1 << idx);
}
int cntBits(int num)
{
	int rt = 0;
	while (num)
	{
		if (num % 2)rt++;
		num /= 2;
	}
	return rt;
}
int mem[1 << 12];
int best(int mask)
{
	int &rt = mem[mask];
	if (~rt)return mem[mask];
	rt = 0;
	for (int i=0;i<10; i++)
	{
		if (getBit(mask, i) && getBit(mask, i + 1) && !getBit(mask, i + 2))
		{
			int tmp_mask = mask;
			tmp_mask = setBit(tmp_mask, i, 0);
			tmp_mask = setBit(tmp_mask, i + 1, 0);
			tmp_mask = setBit(tmp_mask, i + 2, 1);
			rt = max(rt, best(tmp_mask) + 1);
		}
		if (!getBit(mask, i) && getBit(mask, i + 1) && getBit(mask, i + 2))
		{
			int tmp_mask = mask;
			tmp_mask = setBit(tmp_mask, i, 1);
			tmp_mask = setBit(tmp_mask, i + 1, 0);
			tmp_mask = setBit(tmp_mask, i + 2, 0);
			rt = max(rt, best(tmp_mask) + 1);
		}
	}
	return rt;
}
int main(){
	fast
		int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int msk = 0,cnt=0;
		for (int i = 0; i < 12;i++)
		if (s[i] == 'o')
		{
			msk = setBit(msk, i, 1);
			cnt++;
		}
		reset(mem, -1);
		cout << cnt - best(msk) << ed;
	}
}