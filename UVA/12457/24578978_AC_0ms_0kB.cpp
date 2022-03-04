#define _CRT_SECURE_NO_WARNINGS
// to be or not to be !!! Allah_Almost3aan 
//  Make it happen :)
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define stpr(n)fixed<<setprecision(n)
#define reset(mem,val)memset(mem,val,sizeof mem)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
const int N = 1e3 + 3;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int n; 
double p, mem[50][26];
double solve(int play, int won)
{
	if (won == n) return 1;
	if (play == 2 * n - 1) return 0;
	if (mem[play][won] == mem[play][won]) return mem[play][won];
	double rt = solve(play + 1, won + 1)*p + solve(play + 1, won)*(1. - p);
	return mem[play][won]=rt;
}
int main(){
	fast
		int t; cin >> t;
	while (t--)
	{
		reset(mem, -1);
		cin >> n >> p;
		cout << stpr(2) << solve(0, 0) << ed;
	}
}