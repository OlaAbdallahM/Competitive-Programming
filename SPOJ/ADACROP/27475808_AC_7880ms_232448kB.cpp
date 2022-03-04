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
string ys = "YES", no = "NO"; const int N =1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;

int n, Q;
int data[N];
int position[N], value[N];

struct node {
	int sum;
	node *l,*r;
	node() {}
};


int getValue(node* p) {
	return p ? p->sum : 0;
}
node* initialize(int value) {
	node* p = (node*)(malloc(sizeof(node)));
	p->sum = value;
	p->l = NULL;
	p->r = NULL;
	return p;
}
void updatePosition(node* &root, int low, int high, int position, int value) {
	if (!root) {
		root = initialize(0);
	}
	if (low == high) {
		root->sum += value;
		return;
	}
	int middle = (low + high) >> 1;
	if (position <= middle) {
		updatePosition(root->l, low, middle, position, value);
	}
	else {
		updatePosition(root->r, middle + 1, high, position, value);
	}
	root->sum = getValue(root->l) + getValue(root->r);
}
int getInRange(node* &root, int low, int high, int l, int r) {
	if (!root) {
		return 0;
	}
	if (low > r || high < l) {
		return 0;
	}
	if (low >= l && high <= r) {
		return root->sum;
	}
	int middle = (low + high) >> 1;
	return getInRange(root->l, low, middle, l, r)
		+ getInRange(root->r, middle + 1, high, l, r);
}

node* pool[N<<1];

int main(int argc, const char * argv[]) {
	scanf("%d%d", &n, &Q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &position[i], &value[i]);
	}
	vector<int> items = vector<int>(data, data + n);
	items.insert(items.end(), value, value + Q);
	sort(items.begin(), items.end());
	items.erase(unique(items.begin(), items.end()), items.end());

	for (int i = 0; i < n; i++) {
		data[i] = (int)(lower_bound(items.begin(), items.end(), data[i]) - items.begin());
	}
	for (int i = 0; i < Q; i++) {
		value[i] = (int)(lower_bound(items.begin(), items.end(), value[i]) - items.begin());
	}
	for (int i = 0; i < n; i++) {
		updatePosition(pool[data[i]], 1, n, i + 1, 1);
	}
	for (int i = 0; i < Q; i++) {
		printf("%d\n", getInRange(pool[value[i]], 1, n, 1, position[i]));
		if (data[position[i]] != value[i]) {
			updatePosition(pool[data[position[i]]], 1, n, position[i] + 1, -1);
			data[position[i]] = value[i];
			updatePosition(pool[data[position[i]]], 1, n, position[i] + 1, 1);
		}
	}

	return 0;
}