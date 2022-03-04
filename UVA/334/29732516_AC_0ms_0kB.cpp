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



int main(){
	fast;
	int cc = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<string> mapbk;
		map<string, int> map;
		char g[200][200];
		for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			g[i][j] = 0;
		int top = 0;
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			int first = top;
			for (int j = 0; j < m; j++) {
				string s;
				cin >> s;
				map[s] = top;
				mapbk.push_back(s);
				top++;
			}
			for (int j = first; j < top - 1; j++)
				g[j][j + 1] = 1;
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			g[map[s1]][map[s2]] = 1;
		}
		for (int k = 0; k < top; k++)
		for (int i = 0; i < top; i++)
		for (int j = 0; j < top; j++)
			g[i][j] |= g[i][k] & g[k][j];
		string out = "";
		int count = 0;
		for (int i = 0; i < top; i++)
		for (int j = i + 1; j < top; j++) {
			if (!g[i][j] && !g[j][i]) {
				count++;
				if (count <= 2)
					out = out + "(" + mapbk[i] + "," + mapbk[j] + ") ";
			}
		}
		if (count != 0) {
			cout << "Case " << cc++ << ", " << count << " concurrent events:"
				<< endl;
			cout << out << endl;
		}
		else {
			cout << "Case " << cc++ << ", no concurrent events." << endl;
		}
	}
	return 0;
}