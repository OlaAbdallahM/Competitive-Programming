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
string ys = "YES", no = "NO"; const int N = 2 * (1 << 20), M = 1 << 10;
const ll mod = 1e9 + 7;

int n;
// IDEA FROM TUTORIAL
ll tree[2*N], par[N];
vi v;
void build(int ind, int l, int r)
{
	if (l == r)
	{
		tree[ind] = v[l];
		par[l] = ind;
		return;
	}
	int mid = (l + r) >> 1;
	build(ind << 1, l, mid);
	build(ind << 1 | 1, mid + 1, r);
	tree[ind] = tree[ind << 1] + tree[ind << 1 | 1];
}

void update(int place, int val)
{
	int node = par[place];
	tree[node] = val;
	node >>= 1;
	while (node)
	{
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
		node >>= 1;
	}
}

ll query(int ind, int l, int r, int s, int e)
{
	if (e < l || s > r) return 0;
	if (l >= s && r <= e) return tree[ind];
	int mid = (l + r) >> 1;
	return query(ind << 1, l, mid, s, e)
		+ query(ind << 1 | 1, mid + 1, r, s, e);
}

int main()
{
	fast;
	int cnt = 0;
	while (cin >> n&&n){
		if (cnt)cout << ed;
		cout << "Case " << ++cnt << ":\n";
		v.resize(n + 1);
		for (int i = 1; i <= n; i++)cin >> v[i];
		build(1, 1, n);
		char c;
		while (cin >> c){
			if (c == 'M'){
				int l, r; cin >> l >> r;
				cout << query(1, 1, n, l, r) << ed;
			}
			else if (c == 'S'){
				int idx, val;
				cin >> idx >> val;
				//v[idx - 1] = val;
				update(idx, val);
			}
			else{
				cin >> c >> c;
				break;
			}
		}
	}
}