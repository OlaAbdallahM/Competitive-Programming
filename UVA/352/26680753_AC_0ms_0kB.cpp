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
int viz[100][100];
vector<string>v;
int n; 
bool valid(int i, int j){
	return (i >= 0 && i < n&&j >= 0 && j < n&&v[i][j] == '1'&&!viz[i][j]);
}
void dfs(int i, int j){
	viz[i][j]++;
	for (int k = 0; k < 8; k++){
		int ii = i + di[k], jj = j + dj[k];
		if (valid(ii, jj))dfs(ii, jj);
	}
}
int main() {
	fast;
	int cnt = 0;
	while (cin >> n)
	{
		v.resize(n);
		for (auto &i : v) cin >> i;
		reset(viz, 0);
		int ans = 0;
		for (int i = 0; i < n;i++)
		for (int j = 0; j < n;j++)
		if (v[i][j] == '1'&&!viz[i][j])
			ans++,dfs(i, j);
		cout << "Image number "<<++cnt<<" contains "<<ans<<" war eagles.\n";
	}
}

	