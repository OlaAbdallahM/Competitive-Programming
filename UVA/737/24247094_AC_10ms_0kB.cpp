#define _CRT_SECURE_NO_WARNINGS
//  Allah_Almost3aan 
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
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define show(x) cout << (#x)<<" = "<<x<<ed
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
const int N = 2e5 + 5;
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main(){
	fast();
	int x;
	while (cin >> x)
	{
		if (x == 0)break;
		int a, b, c, d, A, B, C, D, ch = 1, Da, Db, Dc;
		cin >> a >> b >> c >> d;
		int da = a + d, db = b + d, dc = c + d;
		for (int i = 1; i<x; i++)
		{
			cin >> A >> B >> C >> D;
			Da = A + D; Db = B + D; Dc = C + D;
			if (A>da || B>db || C>dc || a>Da || b>Db || c>Dc)ch = 0;
			a = max(a, A);
			b = max(b, B);
			c = max(c, C);
			da = min(da, Da);
			db = min(db, Db);
			dc = min(dc, Dc);
		}
		cout<<(ch == 0?0:(da - a)*(db - b)*(dc - c)) << '\n';
	}

}