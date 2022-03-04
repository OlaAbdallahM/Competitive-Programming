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
string ys = "YES", no = "NO"; const int N = 2*(1 << 20), M = 1<<10;
const ll mod = 1e9 + 7;

int n, k, x, y, q, cn, seg[N], lc[N], rc[N], pre[N], root[N];
map <int, vector <int> > oc;
vector <int> a;
                                                     // NOT MY OWN IDEA.
void build(int l=1, int r=n, int pos=root[0]){
	if (l == r){
		seg[pos] = 1;
		return;
	}
	lc[pos] = cn++;
	rc[pos] = cn++;
	int mid = (l + r) / 2;
	build(l, mid, lc[pos]);
	build(mid + 1, r, rc[pos]);
	seg[pos] = seg[lc[pos]] + seg[rc[pos]];
}

void update(int l, int r, int pos, int pos2, int ind, int val){
	seg[pos] = seg[pos2];
	if (l == r){
		seg[pos] = val;
		return;
	}
	int mid = (l + r) / 2;
	if (ind <= mid){
		rc[pos] = rc[pos2];
		lc[pos] = cn++;
		update(l, mid, lc[pos], lc[pos2], ind, val);
	}
	else{
		lc[pos] = lc[pos2];
		rc[pos] = cn++;
		update(mid + 1, r, rc[pos], rc[pos2], ind, val);
	}
	seg[pos] = seg[lc[pos]] + seg[rc[pos]];
}

int query(int l, int r, int pos, int s, int e){
	if (r < s || l > e) return 0;
	if (s <= l && r <= e) return seg[pos];
	int mid = (l + r) / 2;
	return query(l, mid, lc[pos], s, e) + query(mid + 1, r, rc[pos], s, e);
}

int main()
{
	fast;
	a.push_back(0);
	cin >> n >> k;
	for (int i = 1; i <= n && cin >> x; i++)
		a.push_back(x);
	for (int i = 1; i <= n; i++){
		vector<int>&c = oc[a[i]];
		c.push_back(i);
		if (sz(c) <= k)pre[i] = -1;
		else pre[i] = c[sz(c) - k - 1];
	}
	root[0] = cn++;
	build();
	for (int i = 1; i <= n; i++){
		root[i] = cn++;
		if (pre[i] == -1) update(1, n, root[i], root[i - 1], i, 1);
		else update(1, n, root[i], root[i - 1], pre[i], 0);
	}
	cin >> q;
	int last = 0;
	while (q-- && cin >> x >> y){
		x = (x + last) % n + 1;
		y = (y + last) % n + 1;
		if (y < x) swap(x, y);
		last = query(1, n, root[y], x, y);
		cout << last << endl;
	}
}