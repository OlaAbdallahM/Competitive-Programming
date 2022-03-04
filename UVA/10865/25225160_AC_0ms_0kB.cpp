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

double traingle_area(double m1, double m2, double m3)
{
	if (m1 <=0 || m2 <=0 || m3 <=0)return -1;
	double s = 0.5*(m1 + m2 + m3);
	double medains_area = s*(s - m1)*(s - m2)*(s - m3);
	double area = 4. / 3.*sqrt(medains_area);
	return (area <=0 || medains_area <=0 ? -1 : area);
}

long long x[N], y[N], dx, dy;
int n, n2, i, stan, ollie;
int main()
{
	fast;
	while (cin >> n, n)
	{
		for (i = 0; i<n; ++i)
		{
			cin >> x[i] >> y[i];
		}
		n2 = (n >> 1);
		stan = ollie = 0;
		for (i = 0; i<n; ++i)
		{
			dx = x[i] - x[n2];
			dy = y[i] - y[n2];
			if (dx == 0 || dy == 0) continue;
			if (dx*dy > 0) ++stan;
			else ++ollie;
		}
		cout << stan << " " << ollie << endl;
	}
}