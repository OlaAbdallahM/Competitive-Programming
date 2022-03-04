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
string ys = "YES", no = "NO"; const int N = 1 << 20, M = 1 << 10;
const ll mod = 1e9 + 7;

struct Node {
	string c;
	map<string, int> next;
	Node() {
		next.clear();
	}
	void init(string s) {
		c = s;
		next.clear();
	}
} nodes[N];

int Sz = 0;

void insertTrie(vector<string> s) {
	int p = 0;
	for (int i = 0; i < sz(s); i++) {
		if (nodes[p].next.find(s[i]) == nodes[p].next.end()) {
			nodes[++Sz].init(s[i]);
			nodes[p].next[s[i]] = Sz;
		}
		p = nodes[p].next[s[i]];
	}
}
void dfs(int u, int depth) {
	if (u) {
		for (int i = 1; i < depth; i++)
			cout << ' ';
		cout<<nodes[u].c.c_str()<<ed;
	}
	for (map<string, int>::iterator it = nodes[u].next.begin();
		it != nodes[u].next.end(); it++)
		dfs(it->second, depth + 1);
}
int main() {
	fast;
	int n;
	char s[M];
	string token;
	while (cin>>n) {
		nodes[0].init("");
		Sz = 0;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; s[j]; j++)
			if (s[j] == '\\')
				s[j] = ' ';
			stringstream sin(s);
			vector<string> d;
			while (sin >> token)
				d.push_back(token);
			insertTrie(d);
		}
		dfs(0, 0);
		cout << ed;
	}
	return 0;
}