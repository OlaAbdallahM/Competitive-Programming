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
#define ff first
#define ss second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;
const auto EPS = 1e-9;


/*
n^(1/3) = a + dx
n = (a + dx)^3
n = (a^2 + 2*a*dx + dx^2)(a + dx)
n = (a^3 + 2*a^2*dx + a*dx^2 + a^2*dx + 2*a*dx^2 + dx^3)
n = (a^3 + 2*a^2*dx + a^2*dx) [Dropping higher order dx terms]
n = (a^3) + 3*a^2*dx)
dx = (n - a^3) / (3*a^2)
*/

int main()
{
	fast;
	double n,a,dx,ans;
	while (cin >> n){
		if (!n) return 0;

		for (int i = 1;; i++){
			if (i*i*i > n) {
				a = i - 1;
				break;
			}
		}
		//a = floor(pow(n, 1.0 / 3.0) + 0.0000000001);
		dx = ((n - (a*a*a)) / (3 * a*a));
		ans = (a + dx);
		cout << stpr(4)<<ans << ed;
	}
}


