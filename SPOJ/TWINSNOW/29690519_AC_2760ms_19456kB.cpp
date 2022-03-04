#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
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
const int mod = 1e8 + 7, N = 1e7, M = 2001;
map<vi, int>mp;
int main(){
	fast;
	int n; cin >> n;
	vector<vi>v(n,vi(6));
	for (auto &i : v){
		for (auto &j : i)cin >> j;
		mp[i]++;
	}
	bool found = 0;
	for (int x = 0; x < n; x++){
		if (mp.count(v[x])){
			if (mp[v[x]]>1){
				found = 1;
				goto out;
			}
		}
			for (int i = 0; i < 6; i++){
				int j = i, cnt = 6;
				vi tmp;
				while (cnt--){
					j += 6;
					j %= 6;
					tmp.push_back(v[x][j--]);
				}
				j = i, cnt = 6;
				if (mp.count(tmp)){
					found = 1;
					goto out;
				}
				if (i == 0)continue;
				tmp.clear();
				while (cnt--){
					j += 6;
					j %= 6;
					tmp.push_back(v[x][j++]);
				}

				if (mp.count(tmp)){
					found = 1;
					goto out;
				}
			}
		}
out:
	cout << (found ? "Twin snowflakes found." : "No two snowflakes are alike.") << ed;
}
