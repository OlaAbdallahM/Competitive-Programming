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
int n, k,mem[15][100];
int sol(int i, int j)
{
	if (!i)return 0;
	if (!j) return 1;
	int &rt = mem[i][j];
	if (~rt) return rt;
	rt = 0;
	for (int l = 0; l < i&&j - l >= 0; l++)
	{
		rt += sol(i - 1, j - l);
	}
	return rt;
}
int main(){                  
	fast();
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		memset(mem, -1, sizeof mem);
		cout << sol(n,k) << ed;
	}
}
