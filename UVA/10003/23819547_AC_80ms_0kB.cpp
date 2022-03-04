#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan 
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
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
 const int N = (1 << 17);
 int mem[52][52];
 vi v;
 int dp(int a, int b)
 {
	 if (b - a == 1) return 0;
	 if (~mem[a][b]) return mem[a][b];
	 int ans = 4 * 1e6;
	 for (int i = a + 1; i < b; i++)
		 ans = min(ans, v[b] - v[a] + dp(a, i) + dp(i, b));
	 mem[a][b] = ans;
	 return ans;
 }
int main(){       
	fast();        
	while (true)
	{
		int l; 
		cin >> l;
		if (l == 0) break;
		int n; cin >> n;
		v.clear();
		v.push_back(0);
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			v.push_back(x);
		}
		v.push_back(l);
		memset(mem, -1, sizeof mem);
		cout << "The minimum cutting is " << dp(0, n + 1) << ".\n";
	}
}

