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
#define EPS 1e-12
#define PI acos(-1.0)
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
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e8 + 7, N = 2e5+5, M = 2001;


struct point{
	int x, y;
	point(int x = 0, int y = 0) :x(x), y(y){}
	point operator -(point other){
		return point(x - other.x, y - other.y);
	}
	inline bool operator ==(point other){
		return x == other.x&&y == other.y;
	}
};
struct seg{
	point a, b;
}; 
long long  cross(point &v1, point &v2){
	return  1ll * v1.x*v2.y - 1ll * v1.y*v2.x;
}
double norm(point v1){
	return sqrt((v1.x*v1.x) + (v1.y*v1.y));
}
int ccw(point &a, point &b, point &c){
	point v1 = b - a;
	point v2 = c - a;
	if (cross(v1, v2) >EPS)return 1;
	if (cross(v1, v2) <-EPS)return -1;
	if (v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
	if (norm(v1) < norm(v2) - EPS)return 1;
	return 0;
}

bool Inter(point &a, point &b, point &c, point &d){
	point v1 = b - a;
	point v2 = d - c;
	bool f1 = (a == b), f2 = (c == d);
	if (f1&&f2)return a == c;
	if (f1)return ccw(c, d, a) == 0;
	if (f2)return ccw(a, b, c) == 0;
	return ccw(a, b, c) * ccw(a, b, d) <= 0 &&
		ccw(c, d, a) * ccw(c, d, b) <= 0;
}



int main(){
	fast;
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<seg>v(n);
		for (auto &i : v)cin >> i.a.x >> i.a.y >> i.b.x >> i.b.y;
		bool connected[20][20] = { 0 };
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			connected[i][j] = Inter(v[i].a, v[i].b, v[j].a, v[j].b);
		
		for (int k = 0; k < n;k++)
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			connected[i][j] |= (connected[i][k] && connected[k][j]);

		int x, y;
		while (cin >> x >> y){
			if (!x&&!y)break;
			x--; y--;
			cout << (connected[x][y] ? "CONNECTED" : "NOT CONNECTED") << ed;
		}
		if (t)cout<<ed;
	}
}