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
string s1,s2; 
int n,m,idx,idx_shift;
const int N = 100;
int mem[N][N];
int dp(int i, int j)
{
	if (i == sz(s1)) return sz(s2) - j; //add form s2
	if (j == sz(s2)) return sz(s1) - i; // delete from s1
	int &rt = mem[i][j];
	if (~rt) return rt;
	if (s1[i] == s2[j])
		return rt=dp(i + 1, j + 1);
	int choice1 = 1 + dp(i, j + 1); // add form s2[j] before s1
	int choice2 = 1 + dp(i + 1, j); // remove  s1[i]
	int choice3 = 1 + dp(i + 1, j + 1); //replace s1[i]=s2[j]
	return rt = min({ choice1, choice2, choice3 });
}
void build(int i, int j){
	if (i == sz(s1))
	{
		int to_add = sz(s2) - j;
		for (int k = 0; k < to_add; k++)
			cout << ++idx << " Insert " << i + k + 1 + idx_shift << "," << s2[k + j] << ed;
		idx_shift += to_add;
		return;
	}
	if (j == sz(s2))
	{
		int to_delete = sz(s1) - i;
		for (int k = 0; k < to_delete; k++)
		{
			cout << ++idx << " Delete " << i + k + 1 + idx_shift << ed;
			--idx_shift;
		}
		return;
	}
	if (s1[i] == s2[j])
	{
		build(i + 1, j + 1);
		return;
	}
	int choice1 = 1 + dp(i, j + 1); // add form s2[j] before s1
	int choice2 = 1 + dp(i + 1, j); // remove  s1[i]
	int choice3 = 1 + dp(i + 1, j + 1); //replace s1[i]=s2[j]
	int optimal = dp(i, j);
	if (choice1 == optimal)
	{
		cout << ++idx << " Insert " << i + 1 + idx_shift << "," << s2[j] << ed;
		++idx_shift;
		build(i , j + 1);
	}
	else if (choice2 == optimal)
	{
		cout << ++idx << " Delete " << i + 1 + idx_shift << ed;
		--idx_shift;
		build(i + 1, j);
	}
	else
	{
		cout << ++idx << " Replace " << i + 1 + idx_shift << "," << s2[j] << ed;
		build(i + 1, j + 1);
	}
}
int main(){ 
	fast();
	string line = "";
	while (getline(cin,s1)&&getline(cin,s2)){
		line = ed;
		memset(mem, -1, sizeof mem);
		cout << dp(0, 0) << ed;
		idx = idx_shift = 0;
		build(0, 0);
		///cout<<ed;
	}
}
