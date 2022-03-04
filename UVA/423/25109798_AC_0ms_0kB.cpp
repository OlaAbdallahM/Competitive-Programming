#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
//#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define all(c) c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define fr(i,l,n)for(int i=l;i<n;i++)
#define stpr(n)fixed<<setprecision(n)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20;

ll data[101][101];
int n;
int main()
{

	scanf("%d", &n);
	string s;
	for (int i = 0; i < n; i++)
	for (int j = 0; j <= i; j++)
	if (i == j)
	{
		data[i][j] = 0;
	}
	else
	{
		cin >> s;
		if (s == "x")
			data[i][j] = 1e9;
		else
			data[i][j] = stoi(s.c_str());
		data[j][i] = data[i][j];
	}
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		data[i][j] = min(data[i][j], data[i][k] + data[k][j]);
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(data[0][i], ans);
	printf("%lld\n", ans);
}