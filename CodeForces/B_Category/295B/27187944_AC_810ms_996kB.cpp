#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll =  long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1<<10;
const ll mod = 1e9 + 7;

int main() {
	fast;
	int n;  cin >> n;
	vector<vector<int>>d(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> d[i][j];
	vector<int>v(n);
	stack<ll>ans;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v[i]--;
	}
	reverse(all(v));
	vector<bool>vis(n + 1);
	for (int k = 0; k < n; k++)
	{
		vis[v[k]] = true;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = min(d[i][j], d[i][v[k]] + d[v[k]][j]);
		ll sum = 0;
		for (int i = 0; i <n; i++)
		for (int j = 0; j <n; j++)
		if (vis[i] && vis[j])
			sum += d[i][j];
		ans.push(sum);
	}
	while (sz(ans))
	{
		cout << ans.top() << " ";
		ans.pop();
	}
}
//         PST2020L4