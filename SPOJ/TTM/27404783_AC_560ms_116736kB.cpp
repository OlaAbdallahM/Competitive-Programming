#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
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
string ys = "YES", no = "NO"; const int N = 4 * (1 << 17), M = 1 << 10;
const ll mod = 1e9 + 7;

int n, q, a[100005];
#define int long long
struct node{
	int sum, lazy;
	node *left, *right;
	node(int _sum, int _lazy, node *_left, node *_right) {
		sum = _sum;
		lazy = _lazy;
		left = _left;
		right = _right;
	}
	node(int x) {
		sum = x;
		lazy = 0;
		left = right = NULL;
	}
	node(node *l, node *r) {
		sum = l->sum + r->sum;
		lazy = 0;
		left = l; right = r;
	}
};

node *build(int st = 1, int en = n)
{
	if (st == en)
		return new node(a[st]);

	int mid = (st + en) >> 1;
	return new node(build(st, mid), build(mid + 1, en));
}

node *update(node *nod, int l, int r, int ql, int qr, int val) {
	if (l > qr || r < ql) return nod;

	if (l >= ql && r <= qr)
		return new node(nod->sum, nod->lazy + val, nod->left, nod->right);

	int mid = (l + r) >> 1;
	return new node(nod->sum + val * (min(r, qr) - max(l, ql) + 1), nod->lazy,
		update(nod->left, l, mid, ql, qr, val), update(nod->right, mid + 1, r, ql, qr, val));
}

int query(node *nod, int st, int en, int ql, int qr, int val)
{
	if (st > en || st > qr || en <ql)
		return 0;
	val += nod->lazy;
	if (ql <= st && en <= qr)
		return nod->sum + val*(en - st + 1);
	int mid = (st + en) >> 1;;
	return query(nod->left, st, mid, ql, qr, val) + query(nod->right, mid + 1, en, ql, qr, val);
}


node *root[100003];
int32_t main(){
	fast;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> a[i];

	root[0] = build();
	int cur = 0;
	while (q--)
	{
		char c;
		int x, y, t;
		cin >> c;
		if (c == 'B'){
			cin >> t;
			cur = t;
		}
		else if (c == 'Q'){
			cin >> x >> y;
			cout << query(root[cur], 1, n, x, y, 0) << ed;
		}
		else{
			cin >> x >> y >> t;
			if (c == 'C'){
				cur++;
				root[cur] = update(root[cur - 1], 1, n, x, y, t);
			}
			else cout << query(root[t], 1, n, x, y, 0) << ed;
		}
	}

	return 0;
}