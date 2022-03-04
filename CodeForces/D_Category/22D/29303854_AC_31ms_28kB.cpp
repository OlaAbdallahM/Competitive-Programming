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
const ll OO = 1e16;
#define ed '\n'
#define F first
//#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e18, N = 2e5, M = 50000;


int main() {
	fast;
	int n; cin >> n;
	vector<pii>v(n);
	for (auto&i : v){
		cin >> i.first >> i.second;
		if (i.first > i.second)swap(i.first, i.second);
	}
	sort(all(v));
	int end = -1e9;
	vi ans;
	for (auto i : v){
		if (i.first <= end)end = min(end, i.second);
		else{
			if (end != -1e9)ans.push_back(end);
			end = i.second;
		}
		//cout << end << ' ';
	}
	ans.push_back(end);
	cout << sz(ans) << ed;
	for (auto i : ans)cout << i << ' ';
}