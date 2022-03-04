#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
//#include<unorderd_set>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e16;
#define ed '\n'
#define F first
//#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
#define all(c)c.begin(),c.end()
#define RT(v)return cout<<v,0
#define rall(s)s.rbegin(),s.rend()
#define stpr(n)fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO";
const long double rad = acos(-1) / 180, dgr = 180 / acos(-1);
//const int mod = 1e9 + 7, N = 2e5 + 5;


#define Point pair<int, pair<int, int> >
#define X first
#define Y second.first
#define cost second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

char grid[1010][1010];
int vis[1001][1001];
int vis_dir[1001][1001][8];

int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int R, C;

int inside_grid(int x, int y){
	return x >= 0 && y >= 0 && x<R&&y<C;
}

int bfs(int sx, int sy, int fx, int fy){
	memset(vis, -1, sizeof vis);
	memset(vis_dir, -1, sizeof vis_dir);
	queue<Point> q;
	q.push(mp(sx, sy, 0));
	vis[sx][sy] = 0;
	while (!q.empty()){
		Point p = q.front();
		q.pop();
		if (p.X == fx&&p.Y == fy)
			return p.cost;
		if (p.cost>vis[p.X][p.Y] || grid[p.X][p.Y] == 'X' || vis[p.X][p.Y] == -1)
			continue;
		for (int i = 0; i<8; i++){
			int j = 1, nx, ny;
			while (1){
				nx = p.X + dx[i] * j;
				ny = p.Y + dy[i] * j;
				if (inside_grid(nx, ny) && grid[nx][ny] == 'F') {
					return p.cost + 1;
				}
				else if (inside_grid(nx, ny) && grid[nx][ny] != 'X'){
					if (vis_dir[nx][ny][i] != -1) {
						break;
					}
					vis_dir[nx][ny][i] = 1;
					if ((vis[nx][ny] == -1 || vis[nx][ny]>p.cost + 1)){
						q.push(mp(nx, ny, p.cost + 1));
						vis[nx][ny] = p.cost + 1;
					}
				}
				else break;
				j++;
			}
		}
	}
	return -1;
}

int main(){                  // NOT MY SOLUTION 
	int t, sx, sy, fx, fy;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &R, &C);
		for (int i = 0; i<R; i++)
			scanf("%s", grid[i]);
		for (int i = 0; i<R; i++)
		for (int j = 0; j<C; j++)
		if (grid[i][j] == 'S'){
			sx = i; sy = j;
		}
		else if (grid[i][j] == 'F'){
			fx = i; fy = j;
		}
		int bar;
		for (int i = 0; i<R; i++){
			bar = 1;
			for (int j = 0; j<C; j++)
			if (grid[i][j] != 'X'){
				bar = 0;
				break;
			}
			if (bar){
				printf("-1\n");
				break;
			}
		}
		if (bar)
			continue;
		for (int i = 0; i<C; i++){
			bar = 1;
			for (int j = 0; j<R; j++)
			if (grid[j][i] != 'X'){
				bar = 0;
				break;
			}
			if (bar){
				printf("-1\n");
				break;
			}
		}
		if (bar)
			continue;
		printf("%d\n", bfs(sx, sy, fx, fy));
	}
	return 0;
}