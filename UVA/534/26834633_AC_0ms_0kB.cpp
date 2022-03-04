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

vi par;
void init_set(int n) {
	par.assign(n, 0);
	for (int i = 0; i<n; i++) par[i] = i;
}

int find_set(int i) {
	return (par[i] == i) ? i : par[i] = find_set(par[i]);
}

bool is_same_set(int i, int j) {
	return find_set(i) == find_set(j);
}

void union_set(int i, int j) {
	par[find_set(i)] = find_set(j);
}

vector<pii> points;
vector<vi> grid;
int visited[205], tt = 1;

double dist(int i, int j) {
	pii p1 = points[i], p2 = points[j];
	return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

void dfs(int i, double& maxim) {
	if (visited[i]) return;
	if (i == 1) {
		printf("Scenario #%d\nFrog Distance = %.3f\n", tt++, maxim);
		return;
	}
	visited[i] = 1;

	for (auto j:grid[i]) {
		double maxim2 = max(maxim, dist(i,j));
		dfs(j, maxim2);
	}
}

int main() {   // Not my own sol
	int n, x, y;
	while (cin >> n && n) {
		points.clear();
		points.resize(n);
		reset(visited,0);

		for (int i = 0; i<n; i++) {
			cin >> x >> y;
			points[i] = { x, y };
		}

		vector<pair<double, pii> > edge_list;
		for (int i = 0; i<n; i++) {
			for (int j = i + 1; j<n; j++) {
				edge_list.push_back({ dist(i, j), pii(i, j )});
			}
		}
		sort(edge_list.begin(), edge_list.end());
		int E = edge_list.size();
		init_set(n);
		grid.clear();
		grid.resize(n);

		for (int i = 0; i<E; i++) {
			pair<int, pii> front = edge_list[i];
			if (!is_same_set(front.second.first, front.second.second)) {
				int f = front.second.first, s = front.second.second;
				union_set(f, s);
				grid[f].push_back(s);
				grid[s].push_back(f);
			}
		}
		double maxim = 0;
		dfs(0, maxim);
		printf("\n");
	}
	return 0;
}