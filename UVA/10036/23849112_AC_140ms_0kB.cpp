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
int n, k;
vi v;
int mem[10001][101];
bool divs(int i, int mod)
{
	if (i == n)
		return (mod==0);
	int &rt = mem[i][mod];
	if (~rt) return rt;
	rt = divs(i + 1, ((mod + v[i]) % k + k) % k);
	rt |= divs(i + 1, ((mod - v[i]) % k + k) % k);
		return rt;
}
int main(){
	fast();
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		v.resize(n);
		for (auto &i : v) cin >> i;
     	memset(mem, -1, sizeof mem);
		cout << (divs(0,0) ? "Divisible" : "Not divisible") << ed;
	}
}
