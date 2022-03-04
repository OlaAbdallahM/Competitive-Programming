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
//#define S second
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
string ys = "YES", no = "NO"; const int N =1<<20, M = 1 << 10;

int n, t, a[N], Z, freq[N];
ll res[N];

struct qu{
	int l, r, idx;

	qu(){}
	bool operator<(const qu &rhs) const{
		if (l / Z != rhs.l / Z){
			return l < rhs.l;
		}
		return r < rhs.r;
	}
};
qu q[N];

ll ans = 0;

void add(int idx){
	if (a[idx] >= N)return;
	ans -= freq[a[idx]] == a[idx];
	freq[a[idx]]++;
	ans += freq[a[idx]] == a[idx];
}

void remove(int idx){
	if (a[idx] >= N)return;
	ans -= freq[a[idx]] == a[idx];
	freq[a[idx]]--;
	ans += freq[a[idx]] == a[idx];
}

int main(){
	fast;
	cin >> n >> t;
	Z = sqrt(n) + 1;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < t; ++i){
		cin >> q[i].l >> q[i].r;
		q[i].l--;
		q[i].r--;
		q[i].idx = i;
	}
	sort(q, q + t);
	int l = 0, r = -1;
	for (int i = 0; i < t; ++i){
		while (r < q[i].r){
			r++;
			add(r);
		}
		while (r > q[i].r){
			remove(r);
			r--;
		}
		while (l < q[i].l){
			remove(l);
			l++;
		}
		while (l > q[i].l){
			--l;
			add(l);
		}
		res[q[i].idx] = ans;
	}
	for (int i = 0; i < t; ++i)
		cout << res[i] << ed;
}