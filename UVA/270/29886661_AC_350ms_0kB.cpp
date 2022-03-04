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
const int mod = 1e8 + 7, N = 2e5 + 5, M = 2001;

void calc() {
	int res = 0;
	for (int i = 0; i < 700; ++i) {
		for (int j = i + 1; j < 700; ++j) {
			for (int k = j + 1; k < 700; ++k) {
				res++;
			}
		}
	}
	cerr << "COUNT: " << res << "\n";
}
inline bool collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if ((y3 - y2)*(x2 - x1) == (y2 - y1)*(x3 - x2))
		return 1;
	else
		return 0;
}

int main() {
	calc();
		string line;
	int n;
	vector<pii> v;
	int t;
	cin >> t;
	string s;
	cin.ignore();
	getline(cin, line);
	bool f = 0;
	while (t--) {
		v.clear();
		if (f) cout << "\n";
		f = 1;
		while (getline(cin, line)) {
			if (sz(line) == 0)
				break;
			//cerr << line << "\n";
			stringstream ss(line);
			int x, y;
			ss >> x;
			ss >> y;
			v.push_back(pii(x, y));
		}
		int ans = 0;
		for (int i = 0; i < sz(v); ++i) {
			for (int j = i + 1; j < sz(v); ++j) {
				int res = 2;
				for (int k = j + 1; k < sz(v); ++k) {
					if (collinear(v[i].first, v[i].second, v[j].first, v[j].second, v[k].first, v[k].second))
						++res;
				}
				ans = max(ans, res);
			}
		}
		cout << ans << "\n";
	}
}