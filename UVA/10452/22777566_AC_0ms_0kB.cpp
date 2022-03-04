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
int dx[] = { -1, 0, 0 };
int dy[] = { 0, 1, -1 };
string dirc[] = { "forth", "right", "left" };
string path = "IEHOVA#";
vector<vector<char>>v;
vector<string>ans;
int n, m; 
bool valid(int i, int j)
{
	return(i>=0&&i<n&&j>=0&&j<m);
}
void dfs(int i, int j, int indx)
{
	if (indx>sz(path)) return;
	for (int k = 0; k < 3; k++)
	{
		int ii = i + dx[k], jj = j + dy[k];
		if (valid(ii, jj) && v[ii][jj] == path[indx])
		{
			ans.push_back(dirc[k]);
			dfs(ii, jj, indx + 1);
		}
	}
}
int main() {
	fast();
	int q; cin >> q;
	while (q--)
	{
		cin >> n >> m;
		pair<int, int>p;
		v = vector<vector<char>>(n, vector<char>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
					p = { i, j };
			}
		}
		dfs(p.ff, p.ss, 0);
		for (int i = 0; i < sz(ans) - 1; i++)
			cout << ans[i] << " ";
		cout <<ans[sz(ans)-1]<<ed;
		ans.clear();
	}

}
