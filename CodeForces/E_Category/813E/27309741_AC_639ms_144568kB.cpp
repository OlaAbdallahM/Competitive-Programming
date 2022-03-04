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

int n, k, x, a[N];
vi tree[4 * N];
vi pos[N];

void build(int node=1, int st=0, int en=n-1)
{
	if (st > en)
		return;

	if (st == en)
	{
		tree[node].push_back(a[st]);
		return;
	}

	int mid = (st + en) / 2;
	int l = 2 * node, r = l|1;
	build(l, st, mid);
	build(r, mid + 1, en);

	merge(all(tree[l]), all(tree[r]),
		back_inserter(tree[node]));
}

int query(int node, int st, int en, int L, int R, int k)
{
	if (st > en || st > R || en <L)
		return 0;

	if (L <= st && en <= R)
		return lower_bound(all(tree[node]), k) - tree[node].begin();

	int mid = (st + en) / 2;
	int l = 2 * node, r = l|1;
	return query(l, st, mid, L, R, k) + query(r, mid + 1, en, L, R, k);
}

int main(){
	fast;
	cin >> n >> k;
	for (int i = 0; i < n&&cin >> x; i++)
	{
		a[i]=(sz(pos[x]) < k?-1:pos[x][sz(pos[x])-k]);
		pos[x].push_back(i);
	}

	build();

	int l = 0, r = 0, last = 0;

	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		l = ((x + last) % n) + 1;
		r = ((y + last) % n) + 1;
		if (l > r)
			swap(l, r);
		l--, r--;
		last = query(1, 0, n - 1, l, r, l);
		cout << last << endl;
	}

	return 0;
}