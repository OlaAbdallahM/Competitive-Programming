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

struct node {
	node *l,*r;
	int val;
	node() {
		l = r = NULL;
		val = 0;
	}
};

void update(node *cur, int l, int r, int a, int v) {
	if (l > a || r < a)
		return;
	if (l == r)
		return void(cur->val = max(cur->val, v));

	int mid = (l + r) >> 1;
	if (mid >= a) {
		if (!cur->l)
			cur->l = new node();
		update(cur->l, l, mid, a, v);
		cur->val = max(cur->val, cur->l->val);
	}
	else {
		if (!cur->r)
			cur->r = new node();
		update(cur->r, mid + 1, r, a, v);
		cur->val = max(cur->val, cur->r->val);
	}
}

int query(node * cur, int l, int r, int a, int b) {
	if (l > b || r < a || !cur || b < a)
		return 0;
	if (l >= a && r <= b)
		return cur->val;
	int mid = (l + r) >> 1;
	return max(query(cur->l, l, mid, a, b), query(cur->r, mid + 1, r, a, b));
}
node *tree[N];
int main(){
	fast;
	int n, m; 	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		if (!tree[u])
			tree[u] = new node();
		if (!tree[v])
			tree[v] = new node();
		int temp = query(tree[u], 0, N, 0, c - 1);
		ans = max(ans, temp + 1);
		update(tree[v], 0, N, c, temp + 1);
	}

	cout << ans << endl;
}