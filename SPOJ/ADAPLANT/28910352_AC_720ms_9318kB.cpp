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
const long double dgr = acos(-1) / 180;
const int mod = 1e9 + 7, N = 1e5 + 5;
map<int,int>mp;
int main()
{
	fast;
	int t; cin >> t;
	while (t--){
		map<ll, int>mp;
		int n,k; cin >> n >> k;
		k += 2;
		vi v(n); for (auto &i : v) cin >> i;
		priority_queue<int>mn, mx;
		for (int i = 0; i < min(n, k); i++){
			mn.push(-1 * v[i]);
			mx.push(v[i]);
			mp[v[i]]++;
		}
		int ans = abs(mx.top() + mn.top());
		for (int i = k ; i <n; i++){
			
			if (mp[v[i - k]] == 1)mp.erase(v[i - k]);
			else mp[v[i - k]]--;
			mn.push(-1 * v[i]);
			mx.push(v[i]);
			mp[v[i]]++;
			while (sz(mn) && !mp.count(-1 * mn.top())){
				mn.pop();
			}
			while (sz(mx) && !mp.count(mx.top())){
				mx.pop();
			}
			ans = max(ans, abs(mx.top() + mn.top()));
			
		}
		cout << ans << ed;
	}
}


