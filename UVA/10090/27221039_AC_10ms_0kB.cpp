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

int gcd(int a, int b){
	return(!b ? a : a%b);
}

ll Gcd(ll a, ll b)
{
	for (ll t = a % b; t; a = b, b = t, t = a % b); return b;
}

ll extended_euclid(ll a, ll b,ll d, ll &x, ll &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	ll g= extended_euclid(b, a%b,d, y, x);
	y -= (a / b)*x;
	return g;
}

int main(){


	int n; 
	while (cin>>n&&n){
		ll c1, c2, n1, n2;
		cin >> c1 >> n1 >> c2 >> n2;
		ll d = Gcd(n1, n2);
		if (n%d){
			cout << "failed\n";
			continue;
		}
		n /= d; n1 /= d; n2 /= d;
		ll x0, y0, x1, y1, x2, y2, ansx, ansy;
		extended_euclid(n1, n2, d, x0, y0);
		x0 *= n;
		y0 *= n;
		ll a = (ll)ceil(-(double)x0 / n2), b = (ll)floor((double)y0 / n1);
		if (a > b)
		{
			cout<<"failed\n";
			continue;
		}
		x1 = x0 + n2 * a;
		y1 = y0 - n1 * a;
		x2 = x0 + n2 * b;
		y2 = y0 - n1 * b;
		if (x1 * c1 + y1 * c2 < x2 * c1 + y2 * c2)
		{
			ansx = x1;
			ansy = y1;
		}
		else
		{
			ansx = x2;
			ansy = y2;
		}
		//  Solve
		cout << ansx << " " << ansy << endl;
	}
}
