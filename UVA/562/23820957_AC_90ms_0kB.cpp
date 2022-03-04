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
 int mem[105][50005];
 vi v;
 int n,total;
 int dp(int idx, int cur_sum)
 {
	 if (idx==n) return abs(cur_sum-(total-cur_sum));
	 int &rt = mem[idx][cur_sum];
	 if (~rt) return rt;
	 rt = min(dp(idx + 1, cur_sum), dp(idx+1, cur_sum + v[idx]));
	 return rt;
 }
int main(){       
	fast(); 
	int t; cin >> t;
	while (t--)
	{     cin >> n;
	v.clear();  total = 0;
		v.resize(n);
		for (auto &i : v) {
			cin >> i;
			total += i;
		}
		memset(mem, -1, sizeof mem);
		cout <<dp(0,0) <<ed;
	}
}

