#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define all(c) c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define fr(i,l,n)for(int i=l;i<n;i++)
#define stpr(n)fixed<<setprecision(n)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20;
vector<vi>tree;
vi viz, pre;
int bfs(int root)
{
	queue <int> q;
	int level = 1;
	viz[root] = 1;
	q.push(root);
	while (sz(q)){
		int front = q.front();
		q.pop();

		for (auto a : tree[front])
		if (!viz[a]){
			viz[a] = viz[front] + 1;
			level = max(viz[a], level);
			pre[a] = front;
			q.push(a);
		}
	}
	return level;
}
int main()
{
	int n = 0;
	while (cin >> n){
		tree.assign(n,vi(0));
		set <int> best_root;
		set <int> worst_root;

		for (int i = 0; i < n; ++i)
		{
			int count = 0;
			cin >> count;

			for (int j = 0; j < count; ++j)
			{
				int v;
				cin >> v;
				tree[i].push_back(v - 1);
			}
		}

		int root = 0;
		 viz.assign(n, 0);
	      pre.assign(n, -1);
		int max_level = bfs(root);

		int farthest = 0;//next root in the BFS
		for (int i = 0; i < n; ++i)
		if (viz[i] == max_level){
			farthest = i;
			break;
		}

		fill(all(viz), 0);
		fill(all(pre), -1);
		max_level = bfs(farthest);

		farthest = 0;
		for (int i = 0; i < n; ++i)//finding farthest node in the second BFS
		if (viz[i] == max_level)
		{
			farthest = i;
			break;
		}

		stack <int> path;
		while (farthest != -1){
			path.push(farthest);
			farthest = pre[farthest];
		}

		int index = 0;
		int path_size = path.size();

		while (sz(path))
		{
			if (path_size % 2 && index == (path_size / 2))//middle nodes are the best roots
				best_root.insert(path.top());
			else if (path_size % 2 == 0 && (index == path_size / 2 || index == path_size / 2 - 1))
				best_root.insert(path.top());

			++index;
			path.pop();
		}

		for (auto root : best_root){
			fill(all(viz), 0);
			max_level = bfs(root);
			for (int i = 0; i < n; ++i)
			if (viz[i] == max_level)
				worst_root.insert(i);
		}

		cout << "Best Roots  :";
		for (auto a : best_root)
			cout << ' ' << a + 1;
		cout << endl;

		cout << "Worst Roots :";
		for (auto a : worst_root)
			cout << ' ' << a + 1;
		cout << endl;
	}
	return 0;
}

