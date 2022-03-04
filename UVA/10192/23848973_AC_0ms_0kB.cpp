#define _CRT_SECURE_NO_WARNINGS
//   Allah_Almost3aan 
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
using  ll = long long;
const ll OO = 1e18;
#define MOD 1e9+7
#define fnt 0x3f3f3f3f
#define ed '\n'
#define ff first
#define ss second
#define sz(a) a.size()
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define RT(v)return cout<<v<<ed,0
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define stpr(n) fixed<<setprecision(n)
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
string ys = "YES", no = "NO";
void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
char s1[105], s2[105];
int mem[105][105];
int lcs(int i, int j)
{
	if (i == strlen(s1) || j == strlen(s2))
		return 0;
	int &rt = mem[i][j];
	if (~rt) return rt;
	if (s1[i] == s2[j])
		return 1 + lcs(i + 1, j + 1);
	int choice1 = lcs(i + 1, j);
	int choice2 = lcs(i, j + 1);
	return rt=max(choice1, choice2);
}
int main(){
	fast();
	int cnt = 1;
	while (gets(s1)){
		if (s1[0] =='#') return 0;
		gets(s2);
		memset(mem, -1, sizeof mem);
		cout << "Case #" << cnt++ << ": you can visit at most " << lcs(0, 0) << " cities." << ed;
	}
}
