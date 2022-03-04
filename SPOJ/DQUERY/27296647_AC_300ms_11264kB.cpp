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


#define mx 30005
int arr[mx], tree[4 * mx], mp[1000005];
int ans[200005];

struct str
{
	int x, y, ind;
	bool operator<(const str &ob)const
	{
		return y<ob.y;
	}
};

void update(int pos, int b, int e, int i, int j, int val)
{
	if (b>e) return;
	if (b>j || e<i) return;
	if (b >= i && e <= j){
		tree[pos] = val;
		return;
	}
	int mid = (b + e) / 2;
	int left = pos * 2;
	int right = left + 1;
	update(left, b, mid, i, j, val);
	update(right, mid + 1, e, i, j, val);
	tree[pos] = tree[left] + tree[right];
}

int query(int pos, int b, int e, int i, int j)
{
	if (b>e) return 0;
	if (b>j || e<i) return 0;
	if (b >= i && e <= j){
		return tree[pos];
	}
	int mid = (b + e) / 2;
	int left = pos * 2;
	int right = left + 1;
	int q1 = query(left, b, mid, i, j);
	int q2 = query(right, mid + 1, e, i, j);
	return q1 + q2;
}

int main()
{
	int tc, n, q, cs = 1, a, b;
	tc = 1;
	while (tc--){
		reset(tree, 0);
		reset(mp, -1);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
		}
		scanf("%d", &q);

		vector<str> qry(q);

		for (int i = 0; i<q; i++){
			scanf("%d%d", &qry[i].x, &qry[i].y);
			qry[i].ind = i;
		}
		sort(qry.begin(), qry.end());
		int idx = 1;
		for (int i = 0; i<q; i++){
			for (idx; idx <= qry[i].y; idx++){
				int val = arr[idx];
				if (mp[val] == -1){
					mp[val] = idx;
					update(1, 1, n, idx, idx, 1);
				}
				else{
					int ii = mp[val];
					update(1, 1, n, ii, ii, 0);
					mp[val] = idx;
					update(1, 1, n, idx, idx, 1);
				}
			}
			ans[qry[i].ind] = query(1, 1, n, qry[i].x, qry[i].y);
		}
		for (int i = 0; i<q; i++){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}