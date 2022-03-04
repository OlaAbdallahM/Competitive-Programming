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
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
int di[8]={0,0,1,-1,-1,1,-1,1};
int dj[8]={1,-1,0,0,1,1,-1,-1};
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define fr(i,l,n)for(int i=l;i<n;i++)
#define stpr(n)fixed<<setprecision(n)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20;

int main()
{
	fast;
	int t; cin >> t;
	while (t--)
	{
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		int ans_LL_x, ans_LL_y, ans_UR_x, ans_UR_y;
		ans_LL_x = max(x1, x3);
		ans_LL_y = max(y1, y3);
		ans_UR_x = min(x2, x4);
		ans_UR_y = min(y2, y4);
		if (ans_LL_x >= ans_UR_x || ans_LL_y >= ans_UR_y)
			cout << "No Overlap\n";
		else
			cout << ans_LL_x << ' ' << ans_LL_y << ' ' << ans_UR_x << ' ' << ans_UR_y << '\n';
		if (t) cout <<ed;
	}
}