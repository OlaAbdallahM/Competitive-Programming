#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18;
#define ed '\n'
#define F first
//#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//string ys = "YES", no = "NO"; const int N =1<<20, M = 1 << 10;
 
int pre[101];
int main(){
	fast;
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		pre[l]++;
		pre[r]--;
	}
	for (int i = 1; i < n; i++)pre[i] += pre[i - 1];
	for (int i = 0; i < n; i++)
	{
		if (pre[i] != 1)
		{
			cout << i + 1 << " " << pre[i] << "\n";
			return 0;
		}
	}
	cout << "OK\n";

}