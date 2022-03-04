#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll =  long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1<<10;
const ll mod = 1e9 + 7;

vi seg[1 << 18];
int arr[N],n,m,x,y,k;
void build(int ind=0, int n_st=0, int n_en=n-1){
	if (n_st == n_en){
		seg[ind].push_back(arr[n_st]);
		return;
	}
	int l = (ind << 1) + 1,r=l+1,md=(n_st+n_en)>>1;
	build(l, n_st, md); build(r, md + 1, n_en);
	merge(
		seg[l].begin(),
		seg[l].end(),
		seg[r].begin(),
		seg[r].end(),
		inserter(seg[ind], seg[ind].begin())
		);
}
int query(int q_st, int q_en, int q_val, int ind = 0, int n_st = 0, int n_en = n - 1){
	if (n_st > q_en || n_en < q_st) return 0;
	if (n_st >= q_st&&n_en <= q_en)
		return lower_bound(seg[ind].begin(), seg[ind].end(), q_val) - seg[ind].begin();
	
	int l = (ind << 1) + 1, r = l + 1, md = (n_st + n_en) >> 1;
	return query(q_st, q_en, q_val, l, n_st, md) + query(q_st, q_en, q_val, r, md + 1, n_en);
}
int solve(int x, int y, int k){
	int st = -1e9, en = 1e9;
	while (st < en){
		int md = (en + st) >> 1;
		int ans = query(x, y, md);
		if (ans >=k)en = md;
		else st = md + 1;
	}
	return st;;
}
int main()
{
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	build();
	while (m--){
		cin >> x >> y >> k;
		cout << solve(x - 1, y - 1, k)-1 << ed;
	}
}