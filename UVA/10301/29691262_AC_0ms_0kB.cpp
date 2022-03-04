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
const ll OO = 1e18;
#define ed '\n'
#define EPS 1e-12
#define PI acos(-1.0)
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
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e8 + 7, N = 1e7, M = 2001;

typedef pair<double, double> point;

bool interset(point c1, point c2, double r1, double r2)
{
	double disX = c1.first - c2.first,
		disY = c1.second - c2.second,
		rsum = r1 + r2, rdiff = r1 - r2,
		dist = disX*disX + disY*disY;

	return ((dist<rsum*rsum) && (!(dist <= rdiff*rdiff)));
}

vector<pair<point, double>>v;
vector<vi>adj;
int viz[105],cnt;
void dfs(int i){
	viz[i]++;
	cnt++;
	for (auto j : adj[i])
	if (!viz[j])dfs(j);
}
int main(){
	fast;
	int n;
	while (cin >> n){
		if (n == -1)break;
		v.resize(n);
		adj.clear();
		adj.resize(n);
		reset(viz, 0);
		for (auto &i : v)cin >> i.first.first >> i.first.second >> i.second;
		
		for (int i = 0; i< n; i++){
			for (int j = i + 1; j < n;j++)
			if (interset(v[i].first, v[j].first, v[i].second, v[j].second)){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			cnt = 0;
			if (!viz[i])dfs(i);
			ans = max(ans, cnt);
		}
		cout << "The largest component contains " << ans << (ans == 1 ? " ring." : " rings.") << ed;
	}
}
