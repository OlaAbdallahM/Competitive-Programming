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
int m, n;
int p[110], f[110];
int mem[110][10000];

int rec(int i, int w) {
	if (w > m && m < 1800)
		return -1000;
	if (w > m + 200)
		return -1000;
	if (i == n) {
		if (w > m && w <= 2000)
			return -1000;
		return 0;
	}
	int &rt = mem[i][w];
	if (~rt)  return  rt;
	 rt = max(rec(i + 1, w), f[i] + rec(i + 1, w + p[i]));
	 return rt;
}
int main(){
	fast();
	while (cin>>m>>n)
	{
		for (int i = 0; i < n; i++)
			cin >> p[i] >> f[i];
		memset(mem, -1, sizeof mem);
		cout << rec(0, 0) << ed;
	}
}
