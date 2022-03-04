#define _CRT_SECURE_NO_WARNINGS
//                  Allah_Almost3aan       
//      *{ربى..  كنْ لىِ خيرَ مدبر فإنى لا احسنُ التدبير}*
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
#define ed "\n"
#define RT(v) return cout<<v<<ed,0
#define INF 1e9
#define SZ 1000007
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define ff first
#define ss second
#define sz(a) a.size()
#define pi 3.14159265358979323846
ll mod = 1e9 + 7;
int di[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dj[8] = { 0, -1, 0, 1, 1, 1, -1, -1 };
const int N = 1.5 * 10000000 + 16;
const ll  OO = 1e18;
string ys = "Yes", no = "No";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
vector<vector<char>>v;
map<pair<int, int>, int>vis;
int n; 
bool valid(int i, int j)
{
	return(i>=0&&i<n&&j>=0&&j<n);
}
void dfs(int i, int j)
{
	if (!vis[{i, j}])
	{
		vis[{i, j}]++;
		for (int k = 0; k < 8; ++k)
		{
			int ii = di[k] + i;
			int jj = dj[k] + j;
			if (valid(ii,jj) && !vis[{ii,jj}] && v[ii][jj] == '1')
				dfs(ii,jj);
		}
	}
}
int main() {
	fast();
	int cnt = 1;
	while (cin >> n)
	{
		v = vector<vector<char>>(n, vector<char>(n));
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
		vis.clear();
		int ans = 0;
		for (int i = 0; i < n;i++)
		for (int j = 0; j < n; j++)
		{
			if (!vis[{i,j}]&&v[i][j]=='1')
			{
				dfs(i, j);
				ans++;
			}
		}
		cout << "Image number " << cnt++ << " contains " << ans << " war eagles.\n";
	}
}
