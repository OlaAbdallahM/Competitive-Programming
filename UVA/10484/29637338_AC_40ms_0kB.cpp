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
#define F first
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
const int mod = 1e8+7, N = 2e5;


ll n, d,cnt[105];

void solve(){

}

int main(){
	fast;

	while (cin >> n >> d){
		if (!d)break;

		d = abs(d);
		memset(cnt, 0, sizeof cnt);
		for (int i = 2; i <= n; ++i){
			int x = i;
			for (int j = 2; j <= x; ++j){
				while (x%j == 0){
					x /= j;
					++cnt[j];
				}
			}
		}
		int flag = 1;
		for (int i = 2; i <= 100 && flag; ++i){
			while (flag && d%i == 0){
				if (cnt[i] == 0) flag = 0;
				d /= i;
				--cnt[i];
			}
		}
		if (d != 1 && (d>100 || !cnt[d]))
			flag = 0;
		else if (d != 1)
			--cnt[d];
		long long ans = flag;
		for (int i = 0; i <= n; ++i)
			ans *= cnt[i] + 1;
		cout << ans << ed; 
	}
}