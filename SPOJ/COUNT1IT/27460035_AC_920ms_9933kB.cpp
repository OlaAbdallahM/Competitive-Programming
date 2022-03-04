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
//#define sz(a)a.size()
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
string ys = "YES", no = "NO"; const int N =1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;


struct node
{
	int prior, size, val, ans;
	 node *l, *r;
};

int sz(node* t)
{
	return t ? t->size : 0;
}

void upd_sz(node* t)
{
	if (t)t->size = sz(t->l) + 1 + sz(t->r);
}

void split(node* t, node* &l, node* &r, int key){
	if (!t)l = r = NULL;
	else if (t->val <= key)split(t->r, t->r, r, key), l = t;
	else split(t->l, l, t->l, key), r = t;
	upd_sz(t);
}

void mrg(node* &t, node* l, node* r){
	if (!l || !r)t = l ? l : r;
	else if (l->prior > r->prior)mrg(l->r, l->r, r), t = l;
	else mrg(r->l, l, r->l), t = r;
	upd_sz(t);
}

node* init(int val){
	node* ret = (node*)malloc(sizeof(node));
	ret->val = val; ret->size = 1;
	ret->prior = rand();
	ret->l = ret->r = NULL;
	return ret;
}

int find_kth(node* t, int val)
{
	if (sz(t->l) + 1 == val) return t->val;
	if (sz(t->l) >= val) return find_kth(t->l, val);
	else return find_kth(t->r, val - sz(t->l) - 1);
}

void insert(node* &t, node* it){
	if (!t) t = it;
	else if (it->prior>t->prior)split(t, it->l, it->r, it->val), t = it;
	else insert(t->val <= it->val ? t->r : t->l, it);
	upd_sz(t);
}


int main()
{
	fast;

	node* root = NULL;

	int q, c, x, y, n;
	cin >> n >> q;

	while (n--){
		cin >> y;
		insert(root, init(y));
	}

	while (q--){
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			cin >> x;
			node* l, *r;
			split(root, l, r, x);
			int nw = sz(l);
			nw += x;
			mrg(root, l, r);
			insert(root, init(nw));
		}
		else if (ch == 2)
		{
			cin >> x;
			node* l, *r;
			split(root, l, r, x);
			int ans = sz(l);
			mrg(root, l, r);
			cout << ans << ed;
		}
		else
		{
			cin >> x;
			if (sz(root)<x)
				cout << "invalid" << ed;
			else
				cout << find_kth(root, x) << ed;
		}

	}
}