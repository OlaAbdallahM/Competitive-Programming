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
string ys = "YES", no = "NO"; const int N =1<<20, M = 1 << 10;

int adj[61][61], n;

int gcd(int a, int b){
	return(!b ? a : gcd(b, a%b));
}
void dfs(int x, int y){
	int z, a, b, c, d, g, r1, r2;
	for (z = 0; z < n; z++){
		if (x != z && adj[y][z] && !adj[x][z]){
			a = adj[x][y], b = adj[y][x];
			c = adj[y][z], d = adj[z][y];
			g = gcd(b, c);
			r1 = c / g;
			r2 = b / g;
			g = gcd(a * r1, d * r2);
			adj[x][z] = a * r1 / g;
			adj[z][x] = d * r2 / g;
			dfs(x, z);
		}
	}
}

int main(){
	int a, b, x, y, g;
	char cmd[2], tmp[2];
	string s1, s2;
	map<string, int> m;
	while (scanf("%s", cmd), cmd[0] != '.'){
		if (cmd[0] == '!'){
			cin >> a >> s1 >> tmp >> b >> s2;
			if (m.find(s1) == m.end())
				m[s1] = n++;
			if (m.find(s2) == m.end())
				m[s2] = n++;
			x = m[s1], y = m[s2];
			g = gcd(a, b);
			adj[x][y] = a / g;
			adj[y][x] = b / g;
		}
		else{
			cin >> s1 >> tmp >> s2;
			if (m.find(s1) == m.end())
				m[s1] = n++;
			if (m.find(s2) == m.end())
				m[s2] = n++;
			x = m[s1], y = m[s2];
			for (int i = 0; i < n; i++)
			if (adj[x][i])
				dfs(x, i);
			if (adj[x][y])
				cout << adj[x][y] << ' ' << s1 << " = " << adj[y][x] << ' ' << s2 <<ed;
			else
				cout << "? " << s1 << " = " << "? " << s2 <<ed;
		}
	}
	return 0;
}